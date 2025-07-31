#include "Zombie.hpp"

int	main( void )
{
	//* On stack, create a zombie, announce itself, destroy after scope
	randomChump("Satan");

	//* Same but with heap 
	Zombie*	zombie = newZombie("Belzebub");
	zombie->announce();
	//* Then have to be destroy 
	zombie->~Zombie();

	return 0;
}