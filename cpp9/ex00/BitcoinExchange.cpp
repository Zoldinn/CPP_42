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

bool	checkDate( const std::string& line )
{
	for ( int i = 0; i < line.size(); i++ )
	{
		if ( i < 4 && !isdigit(line[i]) )
			return false;
		if ( i == 5 && line[i] != '-' )
			return false;
		if ( i > 5 && i < )
	}
	return true;
}

bool	checkValue( const float& value )
{
	
}

bool	BitcoinExchange::check_dtb_file( const std::fstream& fs )
{
	
}
