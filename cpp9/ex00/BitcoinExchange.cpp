#include "BitcoinExchange.hpp"

/**===========================================================================================
 *                            Constructors, destructor, overloads
 *=========================================================================================**/

BitcoinExchange::BitcoinExchange( void )
{
	std::string	dataPath = PATH_DATA;

	_fill_data_dtb( dataPath );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) { *this = copy; };

BitcoinExchange::~BitcoinExchange( void ) {};

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if ( this != &other )
	{
		this->_data_dtb = other._data_dtb;
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

BitcoinExchange::EFailedOpen::EFailedOpen( std::string& msg ) : _msg(msg) {};

const char*	BitcoinExchange::EFailedOpen::what() const throw()
{
	_msg = "Failed open " + _msg;
	return _msg.c_str();
}

/**===========================================================================================
 *                                           Utils
 *=========================================================================================**/

bool	bfind( const std::string& str, char c )
{
	return ( str.find(c) == std::string::npos ) ? false : true;
}

void	errorMsgSelector( int (&date)[3], const std::string& val )
{
	int			maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// 2009: birth of bitcoin
	if ( date[YEAR] < 2009 || date[YEAR] > 2025 )
		std::cout << "Error: bad input => " << date[YEAR] << '-' << date[MONTH]
					<< '-' << date[DAY] << std::endl;
	else if ( date[MONTH] < 1 || date[MONTH] > 12 )
		std::cout << "Error: bad input => " << date[YEAR] << '-' << date[MONTH]
					<< '-' << date[DAY] << std::endl;
	else if ( date[DAY] < 1 || date[DAY] > (maxDay[date[MONTH]] - 1) )
	{
		// check bissextile year
		if ( date[MONTH] == 2 && date[YEAR] % 400 == 0 && date[DAY] <= 29 )
			return ;
		else
			std::cout << "Error: bad input => " << date[YEAR] << '-' << date[MONTH]
					<< '-' << date[DAY] << std::endl;
	}
	else if ( val.size() > 4 || (val.size() == 4 && val > "1000") )
		std::cout << "Error: too large number" << std::endl;
	else if ( std::strtof(val.c_str(), NULL) < 0 )
		std::cout << "Error: not a positive number" << std::endl;
}

/*================================ Check consistency ==============================*/

bool			checkDateConsistency( int (&date)[3] )
{
	int	maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// 2009: birth of bitcoin
	if ( date[YEAR] < 2009 || date[YEAR] > 2025 )
		return false;
	if ( date[MONTH] < 1 || date[MONTH] > 12 )
		return false;
	if ( date[DAY] < 1 || date[DAY] > ( maxDay[date[MONTH] - 1] ) )
	{
		// check bissextile year
		if ( date[MONTH] == 2 && date[YEAR] % 400 == 0 && date[DAY] <= 29 )
			return true;
		return false;
	}
	return true;
}


bool			checkValueConsistency( const std::string& val )
{
	if ( val.size() > 4 || (val.size() == 4 && val > "1000") || val[0] == '-' )
		return false;
	return true;
}

/*================================ Check format  ==============================*/

bool	checkDateFormat( const std::string& line, int (&valDate)[3] )
{
	std::string			date[3];

	if ( line.size() < 10 )
		return false;

	date[YEAR]	= line.substr( 0, 4 );
	date[MONTH]	= line.substr( 5, 2 );
	date[DAY]	= line.substr( 8, 2 );

	for ( size_t i = 0; i < 3; i++ )
	{
		valDate[i] = 0;
		for ( size_t x = 0; x < date[i].size(); x++ )
		{
			if ( !isdigit(date[i][x]) )
				return false;
		}
		valDate[i] = std::atoi( date[i].c_str() );
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
	for ( size_t i = (val[0] == '-') ? 1 : 0; i < val.size(); i++ )
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
/**===========================================================================================
 *                                Fill the _data_dtb
 *=========================================================================================**/

void	BitcoinExchange::_fill_data_dtb( std::string& dataPath )
{
	std::string	line, date, value;
	int			dateVal[3];
	size_t		sepPos;
	bool		firstSkiped = false;

	_fs_data.open( dataPath.c_str() );
	if ( _fs_data.is_open() == false )
		throw EFailedOpen( dataPath );

	// subject say, file must be "date | value"
	// in fact the file they give have no space, so I accept no space or just 1 space
	while ( getline(_fs_data, line) )
	{
		if ( !firstSkiped ) // to avoid first line
			firstSkiped = true;
		else if ( checkDateFormat(line, dateVal) && bfind(line, ',') && checkValueFormat(line) )
		{
			sepPos 	= line.find(',');
			date	= line.substr( 0, sepPos );
			value	= line.substr( (line[sepPos + 1] == ' ') ? sepPos + 2 : sepPos + 1 );

			_data_dtb[date] = std::strtof( value.c_str(), NULL );
		}
	}
	_fs_data.close();
}

/**========================================================================
 *                                  Solver
 *========================================================================**/

void	BitcoinExchange::solver( std::string& inputFile )
{
	std::string								line, date, value;
	int										dateVal[3];
	size_t									sepPos;
	bool									firstSkiped = false;
	std::map<std::string, float>::iterator	closestData;

	_fs_input.open( inputFile.c_str() );
	if ( _fs_input.is_open() == false )
		throw EFailedOpen( inputFile );

	// subject say, file must be "date | value"
	// in fact the file they give have no space, so I accept no space or just 1 space
	while ( getline(_fs_input, line) )
	{
		if ( !firstSkiped ) // to avoid first line
			firstSkiped = true;
		else if ( checkDateFormat(line, dateVal) && checkValueFormat(line) )
		{
			sepPos 	= line.find( '|' );
			date	= line.substr( 0, sepPos );
			value	= line.substr( (line[sepPos + 1] == ' ') ? sepPos + 2 : sepPos + 1 );

			if ( checkDateConsistency(dateVal) && checkValueConsistency(value) )
			{
				closestData = _data_dtb.find(date);
				if ( closestData == _data_dtb.end() ) // not find
				{
					if ( _data_dtb.lower_bound(date) != _data_dtb.begin() )
						closestData = --_data_dtb.lower_bound(date);
					else
						closestData = _data_dtb.lower_bound(date);
				}
				std::cout << date << "=> " << value << " = "
						  <<  std::strtof( value.c_str(), NULL ) * closestData->second
						  << std::endl;
			}
			else
				errorMsgSelector( dateVal, value );
		}
		else
				errorMsgSelector( dateVal, value );
	}
	_fs_data.close();
}