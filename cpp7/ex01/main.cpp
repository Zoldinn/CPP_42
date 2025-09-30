#include "iter.hpp"

int	main( void )
{
	int	arr1[] = { 1, 2, 3, 4, 5};

	std::cout << "Before" << std::endl;
	iter( arr1, 5, &print );
	std::cout << "Plus one" << std::endl;
	iter( arr1, 5, &plusOne );
	iter( arr1, 5, &print );
	std::cout << "Minus one" << std::endl;
	iter( arr1, 5, &minusOne );
	iter( arr1, 5, &print );

	/*===================================*/
	
	char	arr2[] = { 'a', 'b', 'c', 'd', 'e' };

	std::cout << "Before" << std::endl;
	iter( arr2, 5, &print );
	std::cout << "Plus one" << std::endl;
	iter( arr2, 5, &plusOne );
	iter( arr2, 5, &print );
	std::cout << "Minus one" << std::endl;
	iter( arr2, 5, &minusOne );
	iter( arr2, 5, &print );

	return 0;
}
