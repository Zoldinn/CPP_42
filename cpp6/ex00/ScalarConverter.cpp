#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {};
ScalarConverter::ScalarConverter( const ScalarConverter& copy ) {(void)copy;};
ScalarConverter::~ScalarConverter( void ) {};
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
	(void) other;
	return *this;
}

/*============================================================================*/

bool	isNumber( std::string str )
{
	int	i;
	
	if ( str[0] != '-' || str[0] != '+' || !isdigit(str[0]) )
		return false;
	for ( int i = 1; i < str.length(); i++ )
	{
		if ( !isdigit(str[i]) )
		{
			if ( !(i < str.length() - 1 && str[i] == '.') )
				return false;
			else if ( i == str.length() - 1 && str[i] != 'f' )
				return false;
		}
	}
	return true;
}

void	ScalarConverter::convert( std::string str )
{
	const char*	cstr = str.c_str();
	char		typeChar;
	int			typeInt;
	float		typeFloat;
	double		typeDouble;

	if ( str.length() == 1 && isalpha(static_cast<int>( cstr[0] )) && isprint(cstr[0]) )
		typeChar = static_cast<char>( str[0] );
	else if ( isNumber(str) )
	{
		if ( str.find('f') != std::string::npos )

	}
	else if ()
}