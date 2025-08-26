#include "../headers/Dog.hpp"

/**========================================================================
 *                      Constructors, destructor, overloads
 *========================================================================**/

Dog::Dog( void )
{
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog\t default constructor" << std::endl;
}

Dog::Dog( Dog const & other ) : Animal(other)
{

	*this = other;
	std::cout << "Dog\t copy constructor" << std::endl;
}

Dog::~Dog( void )
{
	delete this->brain;
	std::cout << "Dog\t destroyed" << std::endl;
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