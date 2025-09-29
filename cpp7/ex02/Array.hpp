#pragma once

#include <iostream>

template< typename T >
class Array
{
	public:
		Array( void ) { _array = new T[1](); _size = 1; };
		Array( unsigned int n ) { _array = new T[n](); _size = n; };
		Array( const Array& copy ) { *this = copy; };
		~Array( void ) { delete [] _array; };

		Array&			operator=( const Array& other )
		{
			if ( this != other )
			{
				delete [] this->_array;
				this->_array = new T[other._size]();
				for ( int i = 0; i < size; i++ )
					this->_array[i] = other._array[i];
				this->_size = other._size;
			}
			return *this;
		}
		T&				operator[]( unsigned int i )
		{
			try
			{
				if ( i < 0 || i > this->_size )
					throw std::exception();
				return this->_array[i];
			}
			catch ( const std::exception& e )
			{
				std::cout << "index is out of bounds" << std::endl;
				return _array[0]; //todo: maybe put all in a tpp or cpp (?) for things not template
			}
		}
		unsigned int	size( void ) const;
	
	private:
		T*				_array;
		unsigned int	_size;
};
