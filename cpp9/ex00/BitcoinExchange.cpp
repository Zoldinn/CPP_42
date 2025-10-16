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

size_t	count_word( const std::string& str, const std::string& sep )
{
	size_t	pos   = 0;
	size_t	count = 0;

	while ( pos < str.size() )
	{
		pos = str.find_first_not_of( sep, pos );
		if ( pos == std::string::npos )
			break;
		count += 1;
		pos = str.find_first_of( sep, pos );
	}
	return count;
}

std::string*	split( const std::string& str, const std::string& sep )
{
	size_t			i      = 0;
	size_t			pos    = 0;
	size_t			end	   = 0;
	size_t			nbWord = 0;
	std::string*	split  = NULL;

	nbWord = count_word(str, sep);
	if ( nbWord == 0 )
		return NULL;
	split = new std::string[ nbWord ];
	while ( pos < str.size() && i < nbWord )
	{
		pos = str.find_first_not_of( sep, pos );
		if ( pos == std::string::npos )
			break;
		end = str.find_first_of(sep, pos);
		if ( end == std::string::npos )
			end = str.size();
		split[i++] = str.substr( pos, end - pos );
		pos = end;
	}
	return split;
}

/*================================ Check consistency ==============================*/

bool			checkDateConsistency( std::string& date )
{
	std::string*	strValues	= split(date, "-");
	int				maxDay[12]	= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int				values[3]	= { atoi(strValues[YEAR ].c_str()),
									atoi(strValues[MONTH].c_str()),
									atoi(strValues[DAY  ].c_str()) };

	// 2009: birth of bitcoin
	if ( values[YEAR] < 2009 || values[YEAR] > 2025 )
		return false;
	if ( values[MONTH] < 1 || values[MONTH] > 12 )
		return false;
	if ( values[DAY] < 1 || values[DAY] > ( maxDay[values[MONTH] - 1] ) )
	{
		// check bissextile year
		if ( values[MONTH] == 2 && values[YEAR] % 400 == 0 && values[DAY] <= 29 )
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

/* bool	checkDateFormat( const std::string& line, int (&valDate)[3] )
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
} */

//! V2
bool	checkDateFormat( const std::string& date )
{
	std::string*	values;

	if ( count_word(date, "-") != 3 )
		return false;
	values = split( date, "-" );
	for ( size_t i = 0; i < 3; i++ )
	{
		for ( size_t x = 0; x < values[i].size(); x++ )
		{
			if ( !isdigit(values[i][x]) )
				return false;
		}
	}
	return true;
}

/* bool	checkValueFormat( const std::string& line )
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
} */

//! V2
bool	checkValueFormat( const std::string& value )
{
	for ( size_t i = (value[0] == '-') ? 1 : 0; i < value.size(); i++ )
	{
		if ( !isdigit(value[i]) )
		{
			if ( i != 0 && value[i] != '.' )
				return false;
			if ( i == 0 && value[i] == '.' )
				return false;
		}
	}
	return true;
}

/**===========================================================================================
 *                                Fill the _data_dtb
 *=========================================================================================**/

size_t		getSepPos( std::string& line )
{
	if ( line.find('|') == std::string::npos )
	{
		if ( line.find(',') == std::string::npos )
			return SIZE_T_ERR;
		else
			return line.find( ',' );
	}
	else
		return line.find( '|' );
}

/* void	BitcoinExchange::_fill_data_dtb( std::string& dataPath )
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
			sepPos	= getSepPos( line );
			if ( sepPos == SIZE_T_ERR )
				continue;
			date	= line.substr( 0, sepPos );
			value	= line.substr( (line[sepPos + 1] == ' ') ? sepPos + 2 : sepPos + 1 );

			_data_dtb[date] = std::strtof( value.c_str(), NULL );
		}
	}
	_fs_data.close();
} */

//! V2
void	BitcoinExchange::_fill_data_dtb( std::string& dataPath )
{
	std::string		line;
	std::string*	tab;

	_fs_data.open( dataPath.c_str() );
	if ( _fs_data.is_open() == false )
		throw EFailedOpen( dataPath );

	while ( getline(_fs_data, line) )
	{
		if ( count_word(line, " ,|") != 3 )
			continue;
		tab = split( line, " ,|" );
		if ( checkDateFormat(tab[DATE]) && checkValueFormat(tab[VAL]) )
			_data_dtb[tab[DATE]] = std::strtof( tab[VAL].c_str(), NULL );
		delete [] tab;
	}
	_fs_data.close();
}

/**========================================================================
 *                                  Solver
 *========================================================================**/


void	errorMsgSelector( const std::string& date, const std::string& val )
{
	std::string*	strValues	= split(date, "-");
	int				maxDay[12]	= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int				dateValues[3]	= { atoi(strValues[YEAR ].c_str()),
									atoi(strValues[MONTH].c_str()),
									atoi(strValues[DAY  ].c_str()) };

	// 2009: birth of bitcoin
	if ( dateValues[YEAR] < 2009 || dateValues[YEAR] > 2025 )
		std::cout << "Error: bad input => " << dateValues[YEAR] << '-' << dateValues[MONTH]
					<< '-' << dateValues[DAY] << std::endl;
	else if ( dateValues[MONTH] < 1 || dateValues[MONTH] > 12 )
		std::cout << "Error: bad input => " << dateValues[YEAR] << '-' << dateValues[MONTH]
					<< '-' << dateValues[DAY] << std::endl;
	else if ( dateValues[DAY] < 1 || dateValues[DAY] > (maxDay[dateValues[MONTH]] - 1) )
	{
		// check bissextile year
		if ( dateValues[MONTH] == 2 && dateValues[YEAR] % 400 == 0 && dateValues[DAY] <= 29 )
			return ;
		else
			std::cout << "Error: bad input => " << dateValues[YEAR] << '-' << dateValues[MONTH]
					<< '-' << dateValues[DAY] << std::endl;
	}
	else if ( val.size() > 4 || (val.size() == 4 && val > "1000") )
		std::cout << "Error: too large number" << std::endl;
	else if ( std::strtof(val.c_str(), NULL) < 0 )
		std::cout << "Error: not a positive number" << std::endl;
}

/* void	BitcoinExchange::solver( std::string& inputFile )
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
			sepPos	= getSepPos( line );
			if ( sepPos == SIZE_T_ERR )
				continue;
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
} */


float	BitcoinExchange::_getClosestData( std::string& date )
{
	std::map<std::string, float>::iterator	closestData;

	closestData = _data_dtb.find(date);
	if ( closestData == _data_dtb.end() ) // not find
	{
		if ( _data_dtb.lower_bound(date) != _data_dtb.begin() )
			closestData = --_data_dtb.lower_bound(date);
		else
			closestData = _data_dtb.lower_bound(date);
	}
	return closestData->second;
}

//! V2
void	BitcoinExchange::solver( std::string& inputFile )
{
	std::string								line;
	std::string*							tab;

	_fs_input.open( inputFile.c_str() );
	if ( _fs_input.is_open() == false )
		throw EFailedOpen( inputFile );

	while ( getline(_fs_input, line) )
	{
		if ( count_word(line, " ,|") != 3 )
			continue;
		tab = split( line, " ,|" );
		if ( checkDateFormat(tab[DATE]) && checkValueFormat(tab[VAL]) )
		{
			if ( checkDateConsistency(tab[DATE]) && checkValueConsistency(tab[VAL]) )
			{
				std::cout << tab[DATE] << "=> " << tab[VAL] << " = "
						  << std::strtof( tab[VAL].c_str(), NULL ) * _getClosestData( tab[DATE] )
						  << std::endl;
			}
			else
				errorMsgSelector( tab[DATE], tab[VAL] );
		}
		else
			errorMsgSelector( tab[DATE], tab[VAL] );
		delete [] tab;
	}
	_fs_input.close();
}
