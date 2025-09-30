#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span( unsigned int n );
		Span( const Span& copy );
		~Span( void );

		Span&				operator=( const Span& other );
		void				addNumber( int n );
		void				shortestSpan( void ) const;
		void				longestSpan( void ) const;

	private:
		Span( void );
		unsigned int		_maxSize;
		std::vector<int>	vec;
};
