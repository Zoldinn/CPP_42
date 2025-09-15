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
			if ( !(i < str.length() - 1 && str[i] == '.') )
				return false;
			else if ( i == str.length() - 1 && str[i] != 'f' )
				return false;
		}
	}
	return true;
}

void	convertPseudoLiteral( std::string str )
{
	if ( str == "inff" )
		convertFromFloat( INFF );
	else if ( str == "+inff" )
		convertFromFloat( +INFF );
	else if ( str == "-inff" )
		convertFromFloat( -INFF );
	else if ( str == "nanf" )
		convertFromFloat( NANF );
	else if ( str == "+inf" )
		convertFromDouble( +INF );
	else if ( str == "inf" )
		convertFromDouble( INF );
	else if ( str == "-inf" )
		convertFromDouble( -INF );
	else if ( str == "nan" )
		convertFromDouble( NAN );
	else
		std::cerr << "Error: any type match" << std::endl;
}

void	ScalarConverter::convert( std::string str )
{
	const char*	cstr = str.c_str();

	if ( str.length() == 1 && isalpha( static_cast<int>(cstr[0]) ) && isprint(cstr[0]) )
		convertFromChar( static_cast<char>(str[0]) ); 
	else if ( isNumber(str) )
	{
		if ( str.find('.') != std::string::npos )
		{
			if ( str.find('f') != std::string::npos )
				convertFromFloat( static_cast<float>(atof(cstr)) );
			else
				convertFromDouble( atof(cstr) );
		}
		else
			convertFromInt( atoi( cstr ));
	}
	else
		convertPseudoLiteral( str );
}
