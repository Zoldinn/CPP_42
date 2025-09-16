#include "ScalarConverter.hpp"

void	convertFromChar( std::string str )
{
	char	val = static_cast<char>( str[0] );

	std::cout	<< "char  : "	<< "'" << val << "'" << std::endl
				<< "int   : "	<< static_cast<int>( val ) << std::endl
				<< std::fixed << std::setprecision(1) 
				<< "float : "	<< static_cast<float>( val ) << "f" << std::endl
				<< std::fixed << std::setprecision(1) 
				<< "double: "	<< static_cast<double>( val ) << std::endl;
}

void	convertFromInt( std::string str )
{
	int	val = atoi( str.c_str() );

	if ( val < 0 || val > 255 || !isprint(val) )
		std::cout << "char  : Non displayable" << std::endl;
	else
		std::cout << "char  : " << "'" << static_cast<char>( val ) << "'" << std::endl;
	std::cout	<< "int   : "	<< val << std::endl
				<< std::fixed << std::setprecision(1) 
				<< "float : "	<< static_cast<float>( val ) << "f" << std::endl
				<< std::fixed << std::setprecision(1) 
				<< "double: "	<< static_cast<double>( val ) << std::endl;
}

void	convertFromFloat( std::string str )
{
	float	val = strtof(str.c_str(), NULL);

	if ( std::isinf(val) || std::isnan(val) )
	{
		std::cout	<< "char  : impossible" << std::endl;
		std::cout	<< "int   : impossible" << std::endl;
	}
	else
	{
		if ( !isprint(val) )
			std::cout << "char  : Non displayable" << std::endl;
		else
			std::cout << "char  : " << "'" << static_cast<char>( val ) << "'" << std::endl;
		std::cout << "int   : "	<< static_cast<float>( val ) << std::endl;
	}
	std::cout	<< std::fixed << std::setprecision(1) 
				<< "float : "	<< val << "f" << std::endl;
	std::cout	<< std::fixed << std::setprecision(1) 
				<< "double: "	<< static_cast<double>( val ) << std::endl;
}

void	convertFromDouble( std::string str )
{
	double	val = strtod( str.c_str(), NULL );

	if ( std::isinf(val) || std::isnan(val) )
	{
		std::cout	<< "char  : impossible" << std::endl;
		std::cout	<< "int   : impossible" << std::endl;
	}
	else
	{
		if ( !isprint(val) )
			std::cout << "char  : Non displayable" << std::endl;
		else
			std::cout << "char  : " << "'" << static_cast<char>( val ) << "'" << std::endl;
		std::cout << "int   : "	<< static_cast<float>( val ) << std::endl;
	}
	std::cout	<< std::fixed << std::setprecision(1) 
				<< "float : "	<< static_cast<float>( val ) << "f" << std::endl;
	std::cout	<< std::fixed << std::setprecision(1) 
				<< "double: "	<< val << std::endl;
}
