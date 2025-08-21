#include "DiamondTrap.hpp"

/**========================================================================
 **                        Constructors, destructor
 *========================================================================**/

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap CONSTRUCTOR called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const & name )
{
	std::cout << "DiamondTrap CONSTRUCTOR called" << std::endl;
	this->_name = name;
	ClapTrap::_name = _name + "_clap_name";
}

DiamondTrap::DiamondTrap( DiamondTrap const & other )
{
	*this = other;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap DESTRUCTOR called" << std::endl;
}

/**========================================================================
 **                                OVERLOADS
 *========================================================================**/

DiamondTrap& DiamondTrap::operator=( DiamondTrap const & other )
{
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

/**========================================================================
 **                              FUNCTIONS
 *========================================================================**/

void		DiamondTrap::whoAmI( void )
{
	std::cout << "Name          : " << this->_name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
}
