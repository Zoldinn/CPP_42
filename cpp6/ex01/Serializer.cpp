#include "Serializer.hpp"

uintptr_t	Serializer::serializer( Data* ptr )
{
	return reinterpret_cast<uintptr_t>( ptr );
}

Data*		Serializer::deserializer( uintptr_t raw )
{
	return reinterpret_cast<Data*>( raw );
}