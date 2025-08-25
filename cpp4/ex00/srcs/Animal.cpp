#include "../headers/Animal.hpp"

/**========================================================================
 *                      Constructors, destructor, overloads
 *========================================================================**/

Animal::Animal( void )
{
	this->_type = "...";
	std::cout << "Animal\t default constructor" << std::endl;
}

Animal::Animal( Animal const & other )
{
	this->_type = other._type;
	std::cout << "Animal\t copy constructor" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal\t\t destroyed" << std::endl;
}

Animal& Animal::operator=( Animal const & other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/*=========================================================================*/

std::string	Animal::getType( void ) const
{
	return this->_type;
}

void	Animal::makeSound( void ) const
{
	std::cout << "*** Animal sound ***" << std::endl;
}
