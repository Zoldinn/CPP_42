#include "Zombie.hpp"

int	main( void )
{
	int	N = 5;

	Zombie*	horde = zombieHorde(N, "Soldier");
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;

	return 0;
}