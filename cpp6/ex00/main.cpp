#include "ScalarConverter.hpp"

int	main( int ac, char** av )
{
	if ( ac != 2 )
	{
		std::cerr << "Error: no args" << std::endl;
		return	1;
	}
	ScalarConverter::convert( std::string(av[1]) );

/* // Testes pour les limites de chaques types
	std::cout << std::endl << "=== Limits tests ===" << std::endl << std::endl;

	char	maxChar		= std::numeric_limits<char>::max();
	char	minChar		= std::numeric_limits<char>::min();
	int		maxInt		= std::numeric_limits<int>::max();
	int		minInt		= std::numeric_limits<int>::min();
	float	maxFloat	= std::numeric_limits<float>::max();
	float	minFloat	= -std::numeric_limits<float>::max();
	double	maxDouble	= std::numeric_limits<double>::max();
	double	minDouble	= std::numeric_limits<double>::min();

	std::ostringstream	oss;
	std::string			str;

	oss << maxChar;
	str = oss.str();
	oss.str("");
	oss.clear();
	std::cout << "Test : max char : non displayable" << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;

	oss << minChar;
	str = oss.str();
	oss.str("");
	oss.clear();
	std::cout << "Test : min char : non displayable" << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;

	oss << maxInt;
	str = oss.str();
	oss.str("");
	oss.clear();
	std::cout << "Test : max int : " << str << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;

	oss << minInt;
	str = oss.str();
	oss.str("");
	oss.clear();
	std::cout << "Test : min int : " << str << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;

	oss << maxFloat;
	str = oss.str();
	str += 'f';
	oss.str("");
	oss.clear();
	std::cout << "Test : max float : " << str << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;

	oss << minFloat;
	str = oss.str();
	oss.str("");
	str += 'f';
	oss.clear();
	std::cout << "Test : min float : " << str << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;

	oss << maxDouble;
	str = oss.str();
	oss.str("");
	oss.clear();
	std::cout << "Test : max double : " << str << std::endl;
	ScalarConverter::convert( str );
	std::cout << std::endl;

	oss << minDouble;
	str = oss.str();
	oss.str("");
	oss.clear();
	std::cout << "Test : min double : " << str << std::endl;
	ScalarConverter::convert( str );
 */
	return	0;
}
