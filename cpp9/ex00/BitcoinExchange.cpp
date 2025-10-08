#include "BitcoinExchange.hpp"

/**========================================================================
 *                     Constructors, destructor, overloads
 *========================================================================**/

BitcoinExchange::BitcoinExchange( void ) {};

BitcoinExchange::BitcoinExchange( std::string& tiPath )
{
	std::string	tpPath = PATH_TP;

	_fill( _dtb[TP], _fs[TP], tpPath );
	std::cerr << "(" << tpPath << " loaded successfuly)" << std::endl;
	_fill( _dtb[TI], _fs[TI], tiPath );
	std::cerr << "(" << tiPath << " loaded successfuly)" << std::endl;

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

/**========================================================================
 *                                 Exceptions
 *========================================================================**/

const char*	BitcoinExchange::EWrongFormat::what() const throw()
{
	return "Wrong data format";
}

const char*	BitcoinExchange::EFailedOpen::what() const throw()
{
	return "open() failed";
}

/**========================================================================
 *                                  Utils
 *========================================================================**/

bool	bfind( const std::string& str, char c )
{
	return ( str.find(c) == std::string::npos ) ? false : true;
}

/**========================================================================
 *                          Fill the database (the maps)
 *========================================================================**/

#define YEAR	0
#define MONTH	1
#define DAY		2
bool	checkDate( const std::string& line )
{
	int					valDate[3];
	int					maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::string			date[3];

	if ( line.size() < 10 )
		return false;

	date[DAY]   = line.substr( 0, 4 );
	date[MONTH] = line.substr( 5, 2 );
	date[YEAR]  = line.substr( 8, 2 );

	for ( size_t i = 0; i < 3; i++ )
	{
		for ( size_t x = 0; x < date[i].size(); x++ )
		{
			if ( !isdigit(date[i][x]) )
				return false;
		}
		valDate[i] = std::atoi( date[i].c_str() );
	}

	if ( line[4] != '-' || line[7] != '-' )
		return false;
	// 2009: birth of bitcoin
	if ( valDate[YEAR] < 2009 || valDate[YEAR] > 2025 )
		return false;
	if ( valDate[MONTH] < 1 || valDate[MONTH] > 12 )
		return false;
	if ( valDate[DAY] < 1 || valDate[DAY] > (maxDay[valDate[MONTH]] - 1) )
	{
		// check bissextile year
		if ( valDate[MONTH] == 2 && valDate[YEAR] % 400 == 0 && valDate[DAY] <= 29 )
			return true;
		return false;
	}
	
	return true;
}

bool	checkValue( const std::string& line )
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
	if ( val.size() > 4 || (val.size() == 4 && val > "1000") )
		return false;

	return true;
}

void	BitcoinExchange::_fill( std::map<std::string, float>& dtb, std::fstream& fs, std::string& fsPath )
{
	std::string	line, date, value;
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
		else if ( checkDate(line) && (bfind(line, '|') || bfind(line, ',')) && checkValue(line) )
		{
			sepPos 		= bfind(line, '|') ? line.find('|') : line.find(',');
			date		= line.substr( 0, sepPos );
			value		= line.substr( (line[sepPos + 1] == ' ') ? sepPos + 2 : sepPos + 1 );
			dtb[date]	= std::strtof( value.c_str(), NULL );
		}
	}
	fs.close();
}


/**========================================================================
 *                                   Solver
 *========================================================================**/

void	BitcoinExchange::solver( void ) const
{
	std::map<std::string, float>::const_iterator it;

	for ( int i = 0; i < 2; i++ )
	{
		for ( it = _dtb[i].begin(); it != _dtb[i].end(); it++ )
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << std::endl;
	}
}
