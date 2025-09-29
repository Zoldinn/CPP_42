#include "iter.hpp"

int	main( void )
{
	int	arr[] = { 1, 2, 3, 4, 5};

	std::cout << "Before" << std::endl;
	iter( arr, 5, &print );
	std::cout << "Plus one" << std::endl;
	iter( arr, 5, &plusOne );
	iter( arr, 5, &print );
	std::cout << "Minus one" << std::endl;
	iter( arr, 5, &minusOne );
	iter( arr, 5, &print );

	return 0;
}
