#include "ClapTrap.hpp"

/**========================================================================
 **                        Constructors/Destructor
 *========================================================================**/

ClapTrap::ClapTrap( void ) : _name("...")
{
	this->_damage = 0;
	this->_stamina = 10;
	this->_health = 10;
	std::cout << "ClapTrap CONSTRUCTOR called" << std::endl;
}

ClapTrap::ClapTrap( std::string const name ) : _name(name)
{
	this->_damage = 0;
	this->_stamina = 10;
	this->_health = 10;
	std::cout << "ClapTrap CONSTRUCTOR called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & cpy ) : _damage(0)
{
	std::cout << "ClapTrap COPY constructor called" << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap DESTRUCTOR called" << std::endl;
}

/**========================================================================
 **                             OVERLOADERS
 *========================================================================**/

ClapTrap&		ClapTrap::operator=( ClapTrap const & other )
{
	if (this != &other)
		*this = other;
	std::cout << "ClapTrap ASSIGNEMENT operator called" << std::endl;
	return *this;
}

/**========================================================================
 **                           Actiiooooonnnn !
 *========================================================================**/

void			ClapTrap::attack( const std::string& target )
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
	std::cout << this->_name << " attacks " << target
		<< ", causing " << this->_damage << " points of damage !" 
		<< std::endl;
	this->_stamina -= 1;
}

void			ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << this->_name << " Received " << amount
		<< " points of damage !" << std::endl;
	this->_health -= amount;
}

void			ClapTrap::beRepaired( unsigned int amount )
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
	std::cout << this->_name << " get repaired " << amount << "!" << std::endl;
	this->_health += 1;
	this->_stamina -= 1;
}

/**========================================================================
 **                               Utils
 *========================================================================**/

unsigned int	ClapTrap::getHP( void )
{
	return this->_health;
}