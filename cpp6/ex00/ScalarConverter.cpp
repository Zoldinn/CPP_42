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
	return true;
}

bool	isExpNotation( std::string str )
{
	if ( str[0] != '-' && str[0] != '+' && !isdigit(str[0]) )
		return false;
	for ( size_t i = 0; i < str.length(); i++ )
	{
		if ( !isdigit(str[i]) )
		{
			if ( i == 1 && str[i] != '.' )
				return false;
			else if ( i == 7 && str[i] != 'e' )
				return false;
			else if ( i == 8 && str[i] != '-' && str[i] != '+' )
				return false;
			else if ( i == str.length() - 1 && str[i] == 'f' )
				return false;
		}
	}
	return true;
}

type	typeDetector( std::string str )
{
	const char*	cstr = str.c_str();

	if ( str.length() == 1 && !isdigit( static_cast<int>(cstr[0]) ) )
		return CHAR; 
	else if ( isNumber(str) || isExpNotation(str) )
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
