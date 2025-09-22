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
	if ( str[0] != '-' && str[0] != '+' && !isdigit(str[0]) )
		return false;
	for ( size_t i = 1; i < str.length(); i++ )
	{
		if ( !isdigit(str[i]) )
		{
			if ( i < str.length() - 1 && str[i] != '.' )
				return false;
			else if ( i == str.length() - 1 && str[i] != 'f' )
				return false;
		}
	}
	if ( atoll( str.c_str() ) > std::numeric_limits<int>::max()
		|| atoll( str.c_str() ) < std::numeric_limits<int>::min() )
		return false;
	return true;
}

void	ScalarConverter::convert( std::string str )
{
	const char*	cstr = str.c_str();

	if ( str.length() == 1 && !isdigit( static_cast<int>(cstr[0]) ) && isprint(cstr[0]) )
		convertFromChar( str ); 
	else if ( isNumber(str) )
	{
		if ( str.find('.') != std::string::npos )
		{
			if ( str.find('f') != std::string::npos )
				convertFromFloat( str );
			else
				convertFromDouble( str );
		}
		else
			convertFromInt( str );
	}
	else if ( str == "+inff" || str == "-inff" || str == "nanf" )
		convertFromFloat( str );
	else if ( str == "+inf" || str == "-inf" || str == "nan" )
		convertFromFloat( str );
	else
		std::cerr << "Error: conversion is impossible" << std::endl;
}
