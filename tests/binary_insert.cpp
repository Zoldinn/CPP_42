#include "header.hpp"

/* int		binary_search( std::vector<int> x, int a ) // return pos >= a
{
	int	min = 0, mid = 0, max = 0;

	for ( int i = 0; i < x.size(); i++ )
	{
		min = i;
		mid = x.size() / 2;
		max = x.size();
		if ( x[mid] >= a && x[mid - 1] < a)
			return mid;
		else if ( x[mid] >= a )
		{

		}
	}
} */

void	binary_search( std::vector<int> x, int a, int min, int mid, int max ) // return pos >= a
{
	if ( min == mid && mid == max )
		return;
	
	if ( a > x[mid] )
		binary_search( x, a, mid, ((max - mid) / 2) + mid, max );
	if ( a < x[mid] )
		binary_search( x, a, min, mid / 2, mid );
}

void	binary_merge_sort( std::vector<int> x )
{
	for ( int i = 1; i < x.size(); i++ )
	{
		int	j = i;
		while ( j > 0 && x[i - 1] > x[i] )
		{
			swap( &x[j-1], &x[i] );
			j = j - 1;
		}
	}
}

/* int		main( int ac, char** av )
{
	std::vector<int>	tab;

	if ( ac != 2 )
		return 1;
	tab = to_int( vsplit(av[1], " ") );
	print_vi( tab );

	binary_merge_sort( tab );
	
	std::cout << " ========== res ========== " << std::endl;
	print_vi( tab );

	return 0;
} */

int		main( int ac, char** av )
{
	std::vector<int>	tab;

	if ( ac != 3 )
		return 1;
	tab = to_int( vsplit(av[1], " ") );
	
	int founded = tab.size()/2;
	binary_search( tab, std::atoi(av[2]), 0, founded, tab.size() );
	std::cout << tab[founded] << std::endl;

	return 0;
}