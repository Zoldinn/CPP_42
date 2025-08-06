#include "Harl.hpp"

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	std::string	choice = av[1];

	Harl	harl;

	harl.complain(choice);
	return 0;
}