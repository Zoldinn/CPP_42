#include "header.hpp"

int		main( void )
{
	int			a;
	int			b;
	std::string	c;
	std::string	d;

	/*==============================================================*/	

	a = 1;
	b = 2;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "swap( a, b )";
	::swap( a, b ); std::cout << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;
	
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	/*==============================================================*/	

	c = "chaine1";
	d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "swap( c, d )";
	::swap( c, d ); std::cout << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;
	
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
