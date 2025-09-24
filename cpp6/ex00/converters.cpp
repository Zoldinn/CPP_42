#include "ScalarConverter.hpp"

bool	ft_strtoi( std::string str, int& val )
{
	std::istringstream	iss( str );
	long				tmp;
	
	iss >> tmp;
	if ( iss.fail() )
		return false;
	if ( tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min() )
		return false;
	val = static_cast<int>(tmp);
	return true;
}

int		getDecPrecision( std::string str )
{
	size_t		posDot;
	std::string	decPart;

	posDot = str.find('.');
	if ( posDot != std::string::npos )
	{
		decPart = str.substr( posDot + 1 );
		if ( !decPart.empty() && decPart[decPart.size() - 1] == 'f' )
			return decPart.size() - 1;
		return decPart.size();
	}
	return 0;
}

/*= ========================================  CHAR  ============================================*/

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

/*= =======================================  INT  ===========================================*/

void	convertFromInt( std::string str )
{
	int	val;

	if ( !ft_strtoi( str, val ) )
	{
		std::cout	<< "char  : Non displayable" << std::endl;
		std::cout	<< "int   : outside int limits" << std::endl;
		std::cout	<< std::fixed << std::setprecision( 1 )
					<< "float : " << strtof( str.c_str(), NULL ) << "f" << std::endl;
		std::cout	<< std::fixed << std::setprecision( 1 )
					<< "double: " << strtod( str.c_str(), NULL ) << std::endl;
		return;
	}
	if ( val < 0 || val > 255 || !isprint(val) )
		std::cout	<< "char  : Non displayable" << std::endl;
	else
		std::cout	<< "char  : " << "'" << static_cast<char>( val ) << "'" << std::endl;
	if ( val <= std::numeric_limits<int>::max() && val >= std::numeric_limits<int>::min() )
		std::cout	<< "int   : "	<< val << std::endl;
	else
		std::cout	<< "int   : outside int limits" << std::endl;
	if ( val <= std::numeric_limits<float>::max() && val >= -std::numeric_limits<float>::max() )
	{
		std::cout	<< std::fixed << std::setprecision( 1 )
					<< "float : "	<< static_cast<float>( val ) << "f" << std::endl;
	}
	else
		std::cout	<< "float : outside float limits" << std::endl;
	if ( val <= std::numeric_limits<double>::max() && val >= -std::numeric_limits<double>::max() )
	{
		std::cout	<< std::fixed << std::setprecision( 1 )
					<< "double: "	<< static_cast<double>( val ) << std::endl;
	}
	else
		std::cout	<< "double: outside double limits" << std::endl;
}

/*= ======================================  FLOAT   ===========================================*/

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
			std::cout << "int   : "	<< static_cast<int>( val ) << std::endl;
		else
			std::cout << "int   : outside int limits" << std::endl;
	}
	if ( (val <= std::numeric_limits<float>::max() && val >= -std::numeric_limits<float>::max())
		|| std::isinf(val) || std::isnan(val)  )
	{
		std::cout	<< std::fixed << std::setprecision( getDecPrecision(str) ) 
					<< "float : "	<< val << "f" << std::endl;
	}
	else
		std::cout << "float : outside float limits" << std::endl;
	if ( (val <= std::numeric_limits<double>::max() && val >= -std::numeric_limits<double>::max())
		|| std::isinf(val) || std::isnan(val)  )
	{
		std::cout	<< std::fixed << std::setprecision( getDecPrecision(str) ) 
					<< "double: "	<< static_cast<double>( val ) << std::endl;
	}
	else
		std::cout << "double: outside double limits" << std::endl;
}

/*= =======================================   DOUBLE    ===========================================*/

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
			std::cout << "int   : "	<< static_cast<int>( val ) << std::endl;
		else
			std::cout << "int   : outside int limits" << std::endl;
	}
	if ( (val <= std::numeric_limits<float>::max() && val >= -std::numeric_limits<float>::max())
		|| std::isinf(val) || std::isnan(val)  )
	{
		std::cout	<< std::fixed << std::setprecision( getDecPrecision(str) ) 
					<< "float : "	<< static_cast<float>( val ) << "f" << std::endl;
	}
	else
		std::cout << "float : outside float limits" << std::endl;
	if ( (val <= std::numeric_limits<double>::max() && val >= -std::numeric_limits<double>::max())
		|| std::isinf(val) || std::isnan(val)  )
	{
		std::cout	<< std::fixed << std::setprecision( getDecPrecision(str) ) 
					<< "double: "	<< val << std::endl;
	}
	else
		std::cout << "double: outside double limits" << std::endl;
}
