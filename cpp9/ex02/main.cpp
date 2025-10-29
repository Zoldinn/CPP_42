#include "PmergeMe.hpp"

void	printVec( std::vector<int>& x )
{
	for ( size_t i = 0; i < x.size(); i++ )
		std::cout << x[i] << " ";
	std::cout << std::endl;
}

int	main( int ac, char** av )
{
	PmergeMe*	s;

	if ( ac <= 2 )
	{
		std::cerr << "Error: argument count" << std::endl;
		return 1;
	}
	try { s = new PmergeMe( av ); }
	catch ( std::exception& e )
	{
		std::cout << "Error: wrong value" << std::endl;
		return 1;
	}

	std::vector<int>&	vec = s->getVec();

	std::cout << "Before :" << std::endl;
	printVec( vec );

	std::cout << "After :" << std::endl;
	s->vecFordJohnson( vec );
	printVec( vec );

	delete s;
	return 0;
}