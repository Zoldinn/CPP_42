#include "Serializer.hpp"

uintptr_t	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t>( ptr );
}

Data*		Serializer::deserialize( uintptr_t raw )
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
	x = Serializer::serialize( ptr );
	ptr = Serializer::deserialize( x );
	if ( ptr == save )
		std::cout << "They're the same" << std::endl;
	else
		std::cout << "they're not the same" << std::endl;
	
	return 0;
}
