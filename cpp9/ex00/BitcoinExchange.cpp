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
	{
		delete [] strValues;
		return false;
	}
	if ( values[MONTH] < 1 || values[MONTH] > 12 )
	{
		delete [] strValues;
		return false;
	}
	if ( values[DAY] < 1 || values[DAY] > ( maxDay[values[MONTH] - 1] ) )
	{
		// check bissextile year
		if ( values[MONTH] == 2 && values[YEAR] % 400 == 0 && values[DAY] <= 29 )
		{
			delete [] strValues;
			return true;
		}
		delete [] strValues;
		return false;
	}

	delete [] strValues;
	return true;
}


bool			checkValueConsistency( const std::string& val )
{
	if ( std::strtof(val.c_str(), NULL) > 1000 || val[0] == '-' )
		return false;
	return true;
}



/*================================ Check format  ==============================*/

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
			{
				delete [] values;
				return false;
			}
		}
	}
	delete [] values;
	return true;
}



bool	checkValueFormat( const std::string& value )
{
	for ( size_t i = (value[0] == '-') ? 1 : 0; i < value.size(); i++ )
	{
		if ( !isdigit(value[i]) )
		{
			if ( i != 0 && value[i] == '.' )
				continue;
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



void	BitcoinExchange::_fill_data_dtb( std::string& dataPath )
{
	std::string		line;
	std::string*	tab;
	bool			skipFirstLine = false;

	_fs_data.open( dataPath.c_str() );
	if ( _fs_data.is_open() == false )
		throw EFailedOpen( dataPath );

	while ( getline(_fs_data, line) )
	{
		if ( skipFirstLine == false )
		{
			skipFirstLine = true;
			continue;
		}
		if ( count_word(line, " ,|") != 2 ) // not 3, because the sep isn't counted
		{
			delete [] tab;
			continue;
		}
		tab = split( line, " ,|" );
		if ( !tab )
			continue;
		if ( checkDateFormat(tab[DATE]) && checkValueFormat(tab[VAL]) )
			_data_dtb[tab[DATE]] = std::strtof( tab[VAL].c_str(), NULL );
		delete [] tab;
	}
	_fs_data.close();
}


/**========================================================================
 *                                  Solver
 *========================================================================**/

void	errorMsgSelector( std::string& date, std::string& val )
{
	if ( !checkDateFormat(date) || !checkDateConsistency(date) )
		std::cout << "Error: bad input => " << date << std::endl;
	else if ( !checkValueFormat(val) )
		std::cout << "Error: bad input => " << val << std::endl;
	else if ( std::strtof(val.c_str(), NULL) > 1000 )
		std::cout << "Error: too large number" << std::endl;
	else if ( std::strtof(val.c_str(), NULL) < 0 )
		std::cout << "Error: not a positive number" << std::endl;
}



float&	BitcoinExchange::_getClosestData( std::string& date )
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



void	BitcoinExchange::solver( std::string& inputFile )
{
	std::string		line;
	std::string*	tab;
	bool			skipFirstLine = false;

	_fs_input.open( inputFile.c_str() );
	if ( _fs_input.is_open() == false )
		throw EFailedOpen( inputFile );

	while ( getline(_fs_input, line) )
	{
		if ( skipFirstLine == false )
		{
			skipFirstLine = true;
			continue;
		}
		if ( count_word(line, " ,|") != 2 ) // not 3, because the sep isn't counted
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		tab = split( line, " ,|" );
		if ( checkDateFormat(tab[DATE]) && checkValueFormat(tab[VAL]) )
		{
			if ( checkDateConsistency(tab[DATE]) && checkValueConsistency(tab[VAL]) )
			{
				float	closestData = _getClosestData( tab[DATE] );
				float	lineVal		= std::strtof( tab[VAL].c_str(), NULL );
				std::cout << tab[DATE] << " => " << tab[VAL] << " = "
						  << lineVal * closestData
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
