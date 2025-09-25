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

// Check if str is equivalent to an int, float or double, and accept exponant notation
bool	isNumber( std::string& str )
{
	size_t	i			= 0;
	bool	intDigits	= false;
	bool	decDigits	= false;
	bool	expDigits	= false;

	if ( str[i] == '-' || str[i] == '+' )
		i++;
	while ( i < str.length() && isdigit(str[i]) )
	{
		intDigits = true;
		i++;
	}
	if ( str[i] == '.' )
	{
		i++;
		while ( i < str.length() && isdigit(str[i]) )
		{
			decDigits = true;
			i++;
		}
	}
	if ( intDigits == false || (decDigits == true && intDigits == false) )
		return false;
	if ( i < str.length() && str[i] == 'e' )
	{
		i++;
		if ( i < str.length() && (str[i] == '-' || str[i] == '+') )
		{
			i++;
			while ( i < str.length() && isdigit(str[i]) )
			{
				expDigits = true;
				i++;
			}
		}
		if ( expDigits == false )
			return false;
	}
	if ( i < str.length() && str[i] == 'f' )
		i++;
	if ( i == str.length() )
		return true;
	return false;
}

/*========================================*/

type	typeDetector( std::string str )
{
	const char*	cstr = str.c_str();

	if ( str.length() == 1 && !isdigit( static_cast<int>(cstr[0]) ) )
		return CHAR; 
	else if ( isNumber(str) )
	{
		if ( str.find('.') != std::string::npos )
		{
			if ( str.find('f') != std::string::npos )
				return FLOAT;
			else
				return DOUBLE;
		}
		return INT;
	}
	else if ( str == "+inff" || str == "-inff" || str == "nanf" )
		return FLOAT;
	else if ( str == "+inf" || str == "-inf" || str == "nan" )
		return DOUBLE;
	return ERROR;
}

/*========================================*/

void	ScalarConverter::convert( std::string str )
{
	type	detectedType;
	
	detectedType = typeDetector( str );
	switch (detectedType)
	{
		case CHAR	: convertFromChar( str );	break;
		case INT	: convertFromInt( str );	break;
		case FLOAT	: convertFromFloat( str );	break;
		case DOUBLE	: convertFromDouble( str );	break;
		case ERROR	: std::cerr << "Error: conversion is impossible" << std::endl; break;
	}
}
