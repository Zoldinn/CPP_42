#include "PmergeMe.hpp"

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
}