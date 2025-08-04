#include "Weapon.hpp"

Weapon::Weapon( void ) {};
Weapon::Weapon( std::string weapon ) : _type(weapon) {};
Weapon::~Weapon( void ) {};

const std::string&	Weapon::getType( void ) const
{
	return _type;
}

void	Weapon::setType( std::string type )
{
	_type = type;
}
