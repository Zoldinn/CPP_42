#include "ClapTrap.hpp"

/**========================================================================
 **                        Constructors/Destructor
 *========================================================================**/

ClapTrap::ClapTrap( std::string const name ) : _name(name), _damage(0)
{
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

std::ostream&	operator<<( std::ostream& os, ClapTrap const & obj )
{
	os << "Name    : " << obj.getName() << std::endl;
	os << "Health  : " << obj.getHealth() << std::endl;
	os << "Stamina : " << obj.getStamina() << std::endl;
	os << "Damage  : " << obj.getDamage() << std::endl;
	return os;
}

/**========================================================================
 **                               Getters
 *========================================================================**/

std::string		ClapTrap::getName( void ) const
{
	return this->_name;
}

unsigned int	ClapTrap::getHealth( void ) const
{
	return this->_health;
}

unsigned int	ClapTrap::getStamina( void ) const
{
	return this->_stamina;
}

int const		ClapTrap::getDamage( void ) const
{
	return this->_damage;
}

/**========================================================================
 **                                Setters
 *========================================================================**/

void			ClapTrap::setHealth( unsigned int newAmount )
{
	this->_health = newAmount;
}

void			ClapTrap::setStamina( unsigned int newAmount )
{
	this->_stamina = newAmount;
}

/**========================================================================
 **                           Actiiooooonnnn !
 *========================================================================**/

void			ClapTrap::attack( const std::string& target )
{
	std::cout << "ClapTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getDamage() << " points of damage !" 
		<< std::endl;
}

void			ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->getName() << " Received " << amount
		<< " points of damage !" << std::endl;
	
}

void			ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap " << this->getName() << " get repaired " << amount
		<< ", causing " << this->getDamage() << " points of damage !" 
		<< std::endl;
}
