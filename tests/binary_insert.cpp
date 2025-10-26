#include "header.hpp"

int		binary_search( int i, std::vector<int> x )
{
	int	low, mid, high;

	low = 0; high = i - 1;
	while ( low <= high )
	{
		mid = low + (high - low) / 2;
		if ( x[i] <= x[mid] )
			high = mid - 1;
		else if ( x[mid] < x[i] )
			low = mid + 1;
	}
	return low;
}

void	binary_merge_sort( std::vector<int>& x )
{
	int	pos, tmp;

	for ( int i = 1; i < x.size(); i++ )
	{
		pos = binary_search( i, x );
		tmp = x[i];
		for ( int k = i; k >= pos + 1; k-- )
			x[k] = x[k - 1];
		x[pos] = tmp;
	}
}

int		main( int ac, char** av )
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
}
