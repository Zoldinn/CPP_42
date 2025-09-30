#include "Array.hpp"

int	main( void )
{
	Array<int>	arr1;
	Array<int>	arr2(5);

	for ( unsigned int i = 0; i < arr2.size(); i++ ) { arr2[i] = i; };

	std::cout << "arr1 : " << arr1 << std::endl;
	std::cout << "arr2 : " << arr2 << std::endl;
	std::cout << "arr1 = arr2" << std::endl;
	arr1 = arr2;
	std::cout << "arr1 : " << arr1 << std::endl;
	std::cout << "arr2 : " << arr2 << std::endl;

	std::cout << "try acces an index out of bounds" << std::endl;
	try
	{
		std::cout << "value out of bounds = " << arr1[10] << std::endl;
	}
	catch ( std::exception& e )
	{
		std::cout << "Exception catched" << std::endl;
	}

	std::cout << "Arr1 size = " << arr1.size() << std::endl;
	std::cout << "Arr2 size = " << arr2.size() << std::endl;

	return 0;
}