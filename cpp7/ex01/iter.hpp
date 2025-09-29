#pragma once

#include <iostream>

template <typename T>
void	print( const T& data ) { std::cout << data << std::endl; };

template <typename T>
void	plusOne( T& data ) { data += 1; };

template <typename T>
void	minusOne( T& data ) { data -= 1; };

template <typename T>
void	iter( T arr[], const int size, void (*f)(T&) )
{
	for ( int i = 0; i < size; i++ )
		f( arr[i] );
}

template <typename T>
void	iter( const T arr[], const int size, void (*f)(const T&) )
{
	for ( int i = 0; i < size; i++ )
		f( arr[i] );
}
