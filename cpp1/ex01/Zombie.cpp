#include "Zombie.hpp"

Zombie::Zombie( void ) {};
Zombie::~Zombie( void ) {};

void	Zombie::announce( void )
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	_name = name;
}
