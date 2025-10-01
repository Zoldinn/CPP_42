#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>

class Span
{

	private:
							Span( void );
		unsigned int		_maxSize;
		std::vector<int>	_vec;

	public:
							Span( unsigned int n );
							Span( const Span& copy );
							~Span( void );

		Span&				operator=( const Span& other );
		void				printVec( void );
		int					shortestSpan( void );
		int					longestSpan( void );
		void				addNumber( int n );
		template< typename It >
		void				addNumber( It begin, It end )
		{
			for ( It it = begin; it != end; it++ )
			{
				try 
				{
					if ( _vec.size() >= _maxSize )
						throw Span::EFull();
					_vec.push_back( *it );
				}
				catch ( const Span::EFull& e )
				{
					std::cout << e.what() << std::endl;
				}
			}
		}
		class EFull : public std::exception
		{
			public:
				const char*	what( void ) const throw();
		};
		class EEmpty : public std::exception
		{
			public:
				const char*	what( void ) const throw();
		};
};
