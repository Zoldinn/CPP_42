#pragma once

#include <iostream>

template< typename T >
class Array
{
	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array& copy );
		~Array( void );

		Array&			operator=( const Array& other );
		T&				operator[]( unsigned int i );
		const T&		operator[]( unsigned int i ) const;
		unsigned int	size( void ) const;
	
	private:
		T*				_array;
		unsigned int	_size;
};

template< typename T >
std::ostream&	operator<<( std::ostream& os, const Array<T>& toPrint );

#include "Array.tpp"