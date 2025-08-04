#include "HumanB.hpp"

HumanB::HumanB( void ) {};
HumanB::~HumanB( void ) {};

void	HumanB::attack( void )
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}