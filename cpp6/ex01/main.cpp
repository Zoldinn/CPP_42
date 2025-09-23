#include "Serializer.hpp"

uintptr_t	Serializer::serializer( Data* ptr )
{
	return reinterpret_cast<uintptr_t>( ptr );
}

Data*		Serializer::deserializer( uintptr_t raw )
{
	return reinterpret_cast<Data*>( raw );
}

int	main( void )
{
	Data		a;
	Data*		ptr;
	Data*		save;
	uintptr_t	x;

	ptr = &a;
	save = ptr;
	x = Serializer::serializer( ptr );
	ptr = Serializer::deserializer( x );
	if ( ptr == save )
		std::cout << "They're the same" << std::endl;
	else
		std::cout << "they're not the same" << std::endl;
	
	return 0;
}