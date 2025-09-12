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

void	convertToChar( std::string str )
{
	char	val;

	val
}

void	convertToInt( std::string str )
{

}

void	convertToFloat( std::string str )
{

}

void	convertToDouble( std::string str )
{

}

void	ScalarConverter::convert( std::string str )
{
	convertToChar( str );
	convertToInt( str );
	convertToFloat( str );
	convertToDouble( str );
}