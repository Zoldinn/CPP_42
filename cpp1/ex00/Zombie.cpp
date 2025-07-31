#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {};
Zombie::~Zombie( void ) {};

void	Zombie::announce( void )
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
