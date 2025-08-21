#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	user("BobR42");

	user.attack("mosquito");
	user.takeDamage(20);
	user.beRepaired(20);

	std::cout << "The mosquitos gang attack !" << std::endl;

	while (user.getHP() > 1)
		user.takeDamage(20);

	std::cout << "You have 1 last HP, heal and go to gard mode !" << std::endl;

	user.beRepaired(99);

	user.highFivesGuys();

	return 0;
}
