#include "FragTrap.hpp"

/**========================================================================
 **                        Constructors/Destructor
 *========================================================================**/

FragTrap::FragTrap( std::string const name ) : ClapTrap(name)
{
	this->_damage = 30;
	this->_stamina = 100;
	this->_health = 100;
	std::cout << "FragTrap CONSTRUCTOR called" << std::endl;
}

FragTrap::FragTrap( FragTrap const & cpy )
{
	std::cout << "FragTrap COPY constructor called" << std::endl;
	*this = cpy;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap DESTRUCTOR called" << std::endl;
}

/**========================================================================
 **                             OVERLOADERS
 *========================================================================**/

FragTrap&		FragTrap::operator=( FragTrap const & other )
{
	if (this != &other)
		*this = other;
	std::cout << "FragTrap ASSIGNEMENT operator called" << std::endl;
	return *this;
}

/**========================================================================
 **                               Function
 *========================================================================**/

void			FragTrap::highFivesGuys( void )
{
	std::cout << this->_name << "Request a high five" << std::endl;
}
