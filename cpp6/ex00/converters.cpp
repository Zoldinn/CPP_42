#include "ScalarConverter.hpp"

void	convertFromChar( char val )
{
	std::cout	<< "char  : "	<< val << std::endl
				<< "int   : "	<< static_cast<int>( val ) << std::endl
				<< "float : "	<< static_cast<float>( val ) << std::endl
				<< "double: "	<< static_cast<double>( val ) << std::endl;
}

void	convertFromInt( int val )
{
	if ( !isprint(val) )
		std::cout << "char  : Non displayable" << std::endl;
	else
		std::cout << "char  : " << static_cast<char>( val ) << std::endl;
	std::cout	<< "int   : "	<< val << std::endl
				<< "float : "	<< static_cast<float>( val ) << std::endl
				<< "double: "	<< static_cast<double>( val ) << std::endl;
}

void	convertFromFloat( float val )
{
	if ( val == INFF || val == -INFF || val == +INFF || val == NANF )
	{
		std::cout	<< "char  : impossible" << std::endl;
		std::cout	<< "int   : impossible" << std::endl;
	}
	else
	{
		if ( !isprint(val) )
			std::cout << "char  : Non displayable" << std::endl;
		else
			std::cout << "char  : " << static_cast<char>( val ) << std::endl;
		std::cout << "int   : "	<< static_cast<float>( val ) << std::endl;
	}
	std::cout	<< "float : "	<< val << std::endl;
	std::cout	<< "double: "	<< static_cast<double>( val ) << std::endl;
}

void	convertFromDouble( double val )
{
	if ( val == INF || val == -INF || val == +INF || val == NAN )
	{
		std::cout	<< "char  : impossible" << std::endl;
		std::cout	<< "int   : impossible" << std::endl;
	}
	else
	{
		if ( !isprint(val) )
			std::cout << "char  : Non displayable" << std::endl;
		else
			std::cout << "char  : " << static_cast<char>( val ) << std::endl;
		std::cout << "int   : "	<< static_cast<float>( val ) << std::endl;
	}
	std::cout	<< "float : "	<< static_cast<float>( val ) << std::endl;
	std::cout	<< "double: "	<< val << std::endl;
}
