#include "header.hpp"

int		main( void )
{
	int a = 2;
	int b = 3;

	A< int >::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << A< int >::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << A< int >::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	A< std::string >::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << A< std::string >::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << A< std::string >::max( c, d ) << std::endl;

	return 0;
}
