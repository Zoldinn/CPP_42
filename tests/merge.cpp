#include "header.hpp"

void	move_front( std::vector<int>& a, std::vector<int>& b )
{
	b.push_back( a.front() );
	a.erase( a.begin() );
}

std::vector<int>	merge( std::vector<int>& a, std::vector<int>& b )
{
	std::vector<int>	c;

	while ( a.size() && b.size() )
	{
		if ( a.front() > b.front() )
			move_front( b, c );
		else
			move_front( a, c );
	}
	while ( a.size() )
		move_front( a, c );
	while ( b.size() )
		move_front( b, c );

	return c;
}

void	divide( std::vector<int>& x, std::vector<int>& l, std::vector<int>& r )
{
	while ( x.size() / 2 > 0 )
		move_front( x, l );
	while ( x.size() )
		move_front( x, r );
}

std::vector<int>	merge_sort( std::vector<int>& x )
{
	std::vector<int>	l, r;

	if ( x.size() <= 1 )
		return x;

	divide( x, l, r );
	l = merge_sort( l );
	r = merge_sort( r );

	return merge( l, r );
}

int	main( int ac, char** av )
{
	std::vector<int>	tab;

	if ( ac != 2 )
		return 1;
	tab = to_int( vsplit(av[1], " ") );
	print_vi( tab );

	tab = merge_sort( tab );
	
	std::cout << " ========== res ========== " << std::endl;
	print_vi( tab );

	return 0;
}