#include "ScalarConverter.hpp"

void	convertFromChar( std::string str )
{
	char	val = static_cast<char>( str[0] );

	if ( isprint(val) )
		std::cout << "char  : "	<< "'" << val << "'" << std::endl;
	else
		std::cout << "char  : Non displayable" << std::endl;
	std::cout	<< "int   : "	<< static_cast<int>( val ) << std::endl;
	std::cout	<< std::fixed << std::setprecision(1);
	std::cout	<< "float : "	<< static_cast<float>( val ) << "f" << std::endl;
	std::cout	<< std::fixed << std::setprecision(1);
	std::cout	<< "double: "	<< static_cast<double>( val ) << std::endl;
}

void	convertFromInt( std::string str )
{
	int	val = atoi( str.c_str() );

	if ( val < 0 || val > 255 || !isprint(val) )
		std::cout << "char  : Non displayable" << std::endl;
	else
		std::cout << "char  : " << "'" << static_cast<char>( val ) << "'" << std::endl;
	std::cout	<< "int   : "	<< val << std::endl;
	std::cout	<< std::fixed << std::setprecision(1)
				<< "float : "	<< static_cast<float>( val ) << "f" << std::endl;
	std::cout	<< std::fixed << std::setprecision(1)
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
		if ( val < 0 || val > 255 || !isprint(static_cast<int>(val)) )
			std::cout << "char  : Non displayable" << std::endl;
		else
			std::cout << "char  : " << "'" << static_cast<char>( val ) << "'" << std::endl;
		if ( val <= std::numeric_limits<int>::max() && val >= std::numeric_limits<int>::min() )
			std::cout << "int   : "	<< static_cast<float>( val ) << std::endl;
		else
			std::cout << "int   : outside int limits" << std::endl;
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
		if ( val < 0 || val > 255 || !isprint(static_cast<int>(val)) )
			std::cout << "char  : Non displayable" << std::endl;
		else
			std::cout << "char  : " << "'" << static_cast<char>( val ) << "'" << std::endl;
		if ( val <= std::numeric_limits<int>::max() && val >= std::numeric_limits<int>::min() )
			std::cout << "int   : "	<< static_cast<float>( val ) << std::endl;
		else
			std::cout << "int   : outside int limits" << std::endl;
	}
	if ( val <= std::numeric_limits<float>::max() && val >= std::numeric_limits<float>::min() )
	{
		std::cout	<< std::fixed << std::setprecision(1) 
					<< "float : "	<< static_cast<float>( val ) << "f" << std::endl;
	}
	else
		std::cout << "float : outside float limits" << std::endl;
	std::cout	<< std::fixed << std::setprecision(1) 
				<< "double: "	<< val << std::endl;
}
