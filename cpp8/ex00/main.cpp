#include "easyfind.hpp"
#include <vector>
#include <cstdlib>

int	main( void )
{
	std::vector<int>	vec;
	int					wanted = 5;

	srand( time(NULL) );
	for ( int i = 0; i < 10; i++ )
	{
		vec.push_back( rand() % 100 );
		std::cout << vec[i];
		if ( i + 1 != 10 )
			std::cout << ", ";
	}
	std::cout << std::endl;

	try 
	{
		std::cout << wanted << " found ? : " << easyfind( vec, wanted ) << std::endl;
	}
	catch ( const std::exception& e )
	{
		std::cout << "not found" << std::endl;
	}

	return 0;
}