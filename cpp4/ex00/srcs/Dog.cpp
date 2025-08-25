#include "../headers/Dog.hpp"

/**========================================================================
 *                      Constructors, destructor, overloads
 *========================================================================**/

Dog::Dog( void )
{
	this->_type = "Dog";
	std::cout << "Dog\t default constructor" << std::endl;
}

Dog::Dog( Dog const & other )
{
	*this = other;
	std::cout << "Dog\t copy constructor" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog\t\t destroyed" << std::endl;
}

Dog& Dog::operator=( Dog const & other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/*=========================================================================*/

void	Dog::makeSound( void ) const
{
	std::cout << "*** Wouf ! ***" << std::endl;
}