#include "BitcoinExchange.hpp"

/**===========================================================================================
 *                            Constructors, destructor, overloads
 *=========================================================================================**/

BitcoinExchange::BitcoinExchange( void ) {};

BitcoinExchange::BitcoinExchange( std::string& tiPath )
{
	std::string	tpPath = PATH_TP;

	_fill( _dtb[TP], _fs[TP], tpPath );
	_fill( _dtb[TI], _fs[TI], tiPath );
	//...
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) { *this = copy; };

BitcoinExchange::~BitcoinExchange( void ) {};

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if ( this != &other )
	{
		// don't assign the fs to avoid have 2 fs pointing to the same file
		this->_dtb[TP] = other._dtb[TP];
		this->_dtb[TI] = other._dtb[TI];
	}
	return *this;
}

/**===========================================================================================
 *                                         Exceptions
 *=========================================================================================**/

const char*	BitcoinExchange::EWrongFormat::what() const throw()
{
	return "Wrong data format";
}

const char*	BitcoinExchange::EFailedOpen::what() const throw()
{
	return "open() failed";
}

/**===========================================================================================
 *                                           Utils
 *=========================================================================================**/

bool	bfind( const std::string& str, char c )
{
	return ( str.find(c) == std::string::npos ) ? false : true;
}

/**===========================================================================================
 *                                Fill the database (the maps)
 *=========================================================================================**/

/*================================ Check consistency ==============================*/

#define YEAR	0
#define MONTH	1
#define DAY		2


bool			checkDateConsistency( int* date[3] )
{
	int	maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// 2009: birth of bitcoin
	if ( *date[YEAR] < 2009 || *date[YEAR] > 2025 )
		return false;
	if ( *date[MONTH] < 1 || *date[MONTH] > 12 )
		return false;
	if ( *date[DAY] < 1 || *date[DAY] > (maxDay[*date[MONTH]] - 1) )
	{
		// check bissextile year
		if ( *date[MONTH] == 2 && *date[YEAR] % 400 == 0 && *date[DAY] <= 29 )
			return true;
		return false;
	}
}


bool			checkValueConsistency( const std::string& val )
{
	if ( val.size() > 4 || (val.size() == 4 && val > "1000") )
		return false;
	return true;
}

std::string&	errorMsgSelector( int* date[3], const std::string& val )
{
	int			maxDay[12]   = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::string	dateErrMsg   = "Error: bad input => " + *date[YEAR] + '-' + *date[MONTH] + '-' + *date[DAY];
	std::string	valErrMsg[2] = { "Error: too large a number.", "Error: not a positive number" };

	// 2009: birth of bitcoin
	if ( *date[YEAR] < 2009 || *date[YEAR] > 2025 )
		return dateErrMsg;
	if ( *date[MONTH] < 1 || *date[MONTH] > 12 )
		return dateErrMsg;
	if ( *date[DAY] < 1 || *date[DAY] > (maxDay[*date[MONTH]] - 1) )
	{
		// check bissextile year
		if ( *date[MONTH] == 2 && *date[YEAR] % 400 == 0 && *date[DAY] <= 29 )
			return dateErrMsg;
		return dateErrMsg;
	}

	if ( val.size() > 4 || (val.size() == 4 && val > "1000") )
		return valErrMsg[0];
	else if ( std::strtof(val.c_str(), NULL) < 0 )
		return valErrMsg[1];
}


/*================================ Check format  ==============================*/

bool	checkDateFormat( const std::string& line, int* valDate[3] )
{
	std::string			date[3];

	if ( line.size() < 10 )
		return false;

	date[YEAR]	= line.substr( 0, 4 );
	date[MONTH]	= line.substr( 5, 2 );
	date[DAY]	= line.substr( 8, 2 );

	for ( size_t i = 0; i < 3; i++ )
	{
		for ( size_t x = 0; x < date[i].size(); x++ )
		{
			if ( !isdigit(date[i][x]) )
				return false;
		}
		*valDate[i] = std::atoi( date[i].c_str() );
	}
	if ( line[4] != '-' || line[7] != '-' )
		return false;
	
	return true;
}


bool	checkValueFormat( const std::string& line )
{
	size_t		sepPos;
	std::string	val;

	sepPos = bfind(line, '|') ? line.find('|') : line.find(',');
	sepPos = ( line[sepPos + 1] == ' ' ) ? sepPos + 1 : sepPos;
	val    = line.substr( ++sepPos ); // ++sepPos for starting at value and not at sep

	// only accept positive integer or positive float with a '.', so no '-' neither sign '+'
	for ( size_t i = 0; i < val.size(); i++ )
	{
		if ( !isdigit(val[i]) )
		{
			if ( i != 0 && val[i] != '.' )
				return false;
			if ( i == 0 && val[i] == '.' )
				return false;
		}
	}

	return true;
}

/*========================= the function which fill the databases =========================*/


void	BitcoinExchange::_fill( std::map<std::string, float>& dtb, std::fstream& fs, std::string& fsPath )
{
	std::string	line, date, value;
	int*		dateVal[3];
	size_t		sepPos;
	bool		firstSkiped = false;

	fs.open( fsPath.c_str() );
	if ( fs.is_open() == false )
		throw EFailedOpen();
	
	// subject say, file must be "date | value"
	// in fact the file they give have no space, so I accept no space or just 1 space
	while ( getline(fs, line) )
	{
		if ( !firstSkiped ) // to avoid first line
			firstSkiped = true;
		else if ( checkDateFormat(line, dateVal) && (bfind(line, '|') || bfind(line, ',')) && checkValueFormat(line) )
		{
			sepPos 	= bfind(line, '|') ? line.find('|') : line.find(',');
			date	= line.substr( 0, sepPos );
			value	= line.substr( (line[sepPos + 1] == ' ') ? sepPos + 2 : sepPos + 1 );

			if ( checkDateConsistency(dateVal) && checkValueConsistency(value) )
				dtb[date]		 = std::strtof( value.c_str(), NULL );
			else if ( &dtb != &_dtb[TP] )
				_error_dtb[date] = errorMsgSelector( dateVal, value );
		}
	}
	fs.close();
}


/**===========================================================================================
 *                                          Solver
 *=========================================================================================**/

void	BitcoinExchange::solver( void ) const
{
	std::cout << "==============================================" << std::endl;
	std::map<std::string, float>::const_iterator	it;
	for ( it = _dtb[TI].begin(); it != _dtb[TI].end(); it++ )
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}

	std::cout << "==============================================" << std::endl;
	for ( it = _dtb[TP].begin(); it != _dtb[TP].end(); it++ )
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}

	std::cout << "==============================================" << std::endl;

	std::map<std::string, std::string>::const_iterator	its;
	for ( its = _error_dtb.begin(); its != _error_dtb.end(); its++ )
	{
		std::cout << its->first << " | " << its->second << std::endl;
	}
}
