#include "Harl.hpp"

/**========================================================================
 *                           Constructor/Destructor
 *========================================================================**/


Harl::Harl( void ) {};
Harl::~Harl( void ) {};

/**========================================================================
 *                           Harl comments...
 *========================================================================**/

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std:: cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std:: cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std:: cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years, whereas you "
		<< "started working here just last month." << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std:: cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*==============================================================*/

void	Harl::complain( std::string level )
{
	std::string	levels[4] = {"debug", "info", "warning", "error"};

	void	(Harl::*funcPtr[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}

	switch (i)
	{
		case 0:
			(this->*funcPtr[0])();
		case 1:
			(this->*funcPtr[1])();
		case 2:
			(this->*funcPtr[2])();
		case 3:
			(this->*funcPtr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
