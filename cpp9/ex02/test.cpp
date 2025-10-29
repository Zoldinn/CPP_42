#include <iostream>
#include <vector>
#include <algorithm>

#define LSIZE	21

std::vector<int>	jacobsthalNumbers( void )
{
	std::vector<int>			js, res;
	std::vector<int>::iterator	last;

	res.push_back( 1 );
	js.push_back( 1 ); js.push_back( 3 ); // initialize the suite

	last = js.end() - 1; // last element
	while ( *last < LSIZE )
	{
		for ( int i = *last; i > *(last - 1); i-- )
			res.push_back( i );

		js.push_back( *last + (2 * *(last - 1) ) ); 

		last = js.end() - 1;
	}
	if ( res.size() < LSIZE )
	{
		for ( int i = LSIZE; i > *(last - 1); i-- )
			res.push_back( i );
	}
	return res;
}

int	main( void )
{
	std::vector<int>	x = jacobsthalNumbers();
	for (int i = 0; i < x.size(); i++)
		std::cout << x[i] << " ";
	std::cout << std::endl;
}
