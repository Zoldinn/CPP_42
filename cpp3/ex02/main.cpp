#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	user("Pulpito");

	user.attack("dogo");
	user.takeDamage(20);
	user.beRepaired(20);

	std::cout << "The dogos gang attack !" << std::endl;

	while (user.getHP() > 1)
		user.takeDamage(20);

	std::cout << "You have 1 last HP, try a high five to make peace !" << std::endl;

	user.beRepaired(99);

	user.highFivesGuys();

	return 0;
}
