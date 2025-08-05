#include "Harl.hpp"

int	main( void )
{
	std::string	choice;

	std::cout << "Which level ? : ";
	std::cin >> choice;
	std::cout << std::endl;

	Harl	harl;

	harl.complain(choice);
	return 0;
}