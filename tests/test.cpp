#include "header.hpp"

int	binS( int i, std::vector<int>& x )
{
	int low = 0, mid, high = i - 1;
	while ( low <= high )
	{
		mid = low + ( high - low ) / 2;
		if ( x[i] < x[mid] )
			high = mid - 1;
		else if ( x[mid] < x[i] )
			low = mid + 1;
	}
	return mid;
}