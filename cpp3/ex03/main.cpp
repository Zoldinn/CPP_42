#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	user("Hero");

	user.attack("Truck-kun");
	user.takeDamage(20);
	user.beRepaired(20);

	std::cout << "Truck-kun will isekai you !" << std::endl;

	while (user.getHP() > 1)
		user.takeDamage(20);

	std::cout << "The Hero have been "
		<< "hurt so badly he doesn't remember is name"
		<< ", use whoAmI() !" << std::endl;

	user.whoAmI();

	return 0;
}
