#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	user("Bob");

	user.attack("mosquito");
	user.takeDamage(1);
	user.beRepaired(1);

	std::cout << "The mosquitos gang attack !" << std::endl;

	while (user.getHP() > 0)
		user.takeDamage(1);

	std::cout << "Try to repair yourself !" << std::endl;

	user.beRepaired(10);

	return 0;
}
