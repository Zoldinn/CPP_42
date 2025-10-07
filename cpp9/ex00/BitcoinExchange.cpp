#include "BitcoinExchange.hpp"

/**========================================================================
 *                     Constructors, destructor, overloads
 *========================================================================**/

BitcoinExchange::BitcoinExchange( void ) {};

BitcoinExchange::BitcoinExchange( std::string& tiPath )
{
	std::string	tpPath = PATH_TP;

	_fill( _dtb_tp, _fs_tp, tpPath );
	_fill( _dtb_ti, _fs_ti, tiPath );

}

/**========================================================================
 *                                 Exceptions
 *========================================================================**/

const char*	BitcoinExchange::EWrongFormat::what() const throw()
{
	return "Wrong data format";
}

/**========================================================================
 *                                 Functions
 *========================================================================**/

void	BitcoinExchange::_fill( std::map<std::string, float>& dtb, std::fstream& fs, std::string& fsPath )
{
	std::string	line, date, value;
	size_t		sepPos;
	
	fs.exceptions( std::fstream::badbit | std::fstream::failbit );
	fs.open( fsPath, std::fstream::in ); // if fail, .open() throw and main catch it
	
	// subject say, file must be "date | value"
	// in fact the file they give have no space, so I accept no space or just 1 space
	while ( getline(fs, line) )
	{
		sepPos		= ( line.find('|') == std::string::npos ) ? line.find(',') : line.find('|');
		date		= line.substr( 0, sepPos );
		value		= line.substr( (line[sepPos + 1] == ' ') ? sepPos + 2 : sepPos + 1 );
		dtb[date]	= std::strtof( value.c_str(), NULL );
	}
	fs.close();
}

/*==========================================================================*/

#define YEAR	0
#define MONTH	1
#define DAY		2
bool	checkDate( const std::string& line )
{
	std::string			date[3];
	int					valDate[3];
	std::map<int, int>	maxDay{ { 1, 31}, { 2, 28}, { 3, 31}, { 4, 30}, { 5, 31}, { 6, 30},
								{ 7, 31}, { 8, 31}, { 9, 30}, { 10, 31}, { 11, 30}, { 12, 31} };

	if ( line.size() < 10 )
		return false;

	date[DAY]   = line.substr( 0, 4 );
	date[MONTH] = line.substr( 5, 2 );
	date[YEAR]  = line.substr( 8, 2 );

	for ( int i = 0; i < 3; i++ )
	{
		for ( int x = 0; x < date[i].size(); x++ )
		{
			if ( !isdigit(date[i][x]) )
				return false;
		}
		valDate[i] = std::atoi( date[i].c_str() );
	}
	if ( line[4] != '-' || line[7] != '-' )
		return false;
	if ( valDate[YEAR] < 2009 || valDate[YEAR] > 2025 ) // 2009: birth of bitcoin
		return false;
	if ( valDate[MONTH] < 1 || valDate[MONTH] > 12 )
		return false;
	if ( valDate[DAY] < 1 || valDate[DAY] > maxDay[ valDate[MONTH] ] )
	{
		if ( valDate[MONTH] == 2 && valDate[YEAR] % 400 == 0 && valDate[DAY] <= 29 ) // check bissextile year
			return true;
		return false;
	}
	
	return true;
}

bool	checkValue( const float& value )
{
	
}

bool	BitcoinExchange::check_dtb_file( const std::fstream& fs )
{
	
}
