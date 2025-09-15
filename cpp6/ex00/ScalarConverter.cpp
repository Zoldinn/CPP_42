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
	if ( str[0] != '-' || str[0] != '+' || !isdigit(str[0]) )
		return false;
	for ( size_t i = 1; i < str.length(); i++ )
	{
		if ( !isdigit(str[i]) )
		{
			if ( !( i < str.length() - 1 && str[i] == '.' ) )
				return false;
			else if ( i == str.length() - 1 && str[i] != 'f' )
				return false;
		}
	}
	return true;
}

void*	isPseudoLiteral( std::string str )
{
	if ( str == "-inff" || str == "+inff" || str == "nanf" )
		return	new float( static_cast<float>( atof(str.c_str()) ) );
	if ( str == "-inf" || str == "+inf" || str == "nan" )
		return	new double( atof(str.c_str()) );
	return	NULL;
}

void*	getType( std::string str )
{
	const char*	cstr = str.c_str();

	if ( str.length() == 1 && isalpha(static_cast<int>( cstr[0] )) && isprint(cstr[0]) )
		return	new char( static_cast<char>( str[0] ) ); 
	if ( isNumber(str) )
	{
		if ( str.find('.') != std::string::npos )
		{
			if ( str.find('f') != std::string::npos )
				return	new float( static_cast<float>( atof(cstr) ) );
			return	new double( atof(cstr) );
		}
		return	new int( atoi(cstr ));
	}
	return	new void*( isPseudoLiteral(str) );
}

void	convertFromChar( char* val )
{
	std::cout	<< "char: " << val << std::endl
				<< static_cast<int>( *val ) << std::endl
				<< static_cast<float>( *val ) << std::endl
				<< static_cast<double>( *val ) << std::endl;
}

void	convertFromInt( int* val )
{
	
}

// todo : limits
void	ScalarConverter::convert( std::string str )
{
	void*	val;
	char*	charVal;
	int*	intVal;
	float*	floatVal;
	double*	doubleVal;

	val	= getType( str );
	if (!val)
	{
		std::cout << "Don't match any type" << std::endl;
		return ;
	}
	charVal*		= convertToChar( val );
	intVal*		= convertToInt( val );
	floatVal*	= convertToFloat( val );
	doubleVal*	= convertToDouble( val );

	std::cout	<< *charVal		<< std::endl
				<< *intVal		<< std::endl
				<< *floatVal	<< std::endl
				<< *doubleVal	<< std::endl;
	delete	val;
}