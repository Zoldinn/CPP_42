#include "ScavTrap.hpp"

/**========================================================================
 **                        Constructors/Destructor
 *========================================================================**/

ScavTrap::ScavTrap( void ) : ClapTrap("")
{
	this->_damage = 20;
	this->_stamina = 50;
	this->_health = 100;
	std::cout << "ScavTrap CONSTRUCTOR called" << std::endl;
}

ScavTrap::ScavTrap( std::string const name ) : ClapTrap(name)
{
	this->_damage = 20;
	this->_stamina = 50;
	this->_health = 100;
	std::cout << "ScavTrap CONSTRUCTOR called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & cpy ) : ClapTrap(cpy._name)
{
	std::cout << "ScavTrap COPY constructor called" << std::endl;
	*this = cpy;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap DESTRUCTOR called" << std::endl;
}

/**========================================================================
 **                             OVERLOADERS
 *========================================================================**/

ScavTrap&		ScavTrap::operator=( ScavTrap const & other )
{
	if (this != &other)
		*this = other;
	std::cout << "ScavTrap ASSIGNEMENT operator called" << std::endl;
	return *this;
}

/**========================================================================
 **                               Function
 *========================================================================**/

void			ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gate keeper mode !" << std::endl;
}

void			ScavTrap::attack( const std::string& target )
{
	if (this->_stamina <= 0)
	{
		std::cout << "You're out of stamina !" << std::endl;
		return ;
	}
	if (this->_health <= 0)
	{
		std::cout << "You died ! How could you do ?" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_damage << " points of damage !" 
		<< std::endl;
	this->_stamina -= 1;
}
