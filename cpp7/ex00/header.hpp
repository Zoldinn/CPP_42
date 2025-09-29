#pragma once

#include <iostream>

template< typename T >
class A
{
	public:
		static void		swap( T& a, T& b )
		{
			T tmp = a;
			a = b;
			b = tmp;
		}
		static T		max( T a, T b ) { return ( a > b ) ? a : b; };
		static T		min( T a, T b ) { return ( a < b ) ? a : b; };
	
	private:
		A( void );
		A( const A& copy );
		~A( void );
		A&	operator=( const A& other );
};
