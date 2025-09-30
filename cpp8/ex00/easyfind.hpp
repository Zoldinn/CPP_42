#pragma once

#include <iostream>
#include <algorithm>

template< typename T >
int&	easyfind( T& container, int toFind )
{
	typename T::iterator	it;

	it = find( container.begin(), container.end(), toFind );
	if ( it == container.end() )
		throw std::exception();
	return *it;
}
