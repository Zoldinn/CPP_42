#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	void*	data;
}	Data;


class Serializer
{
	public:
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );
	
	private:
		Serializer( void );
		Serializer( const Serializer& copy );
		~Serializer( void );
		Serializer&	operator=( const Serializer& other );
};