#include "../headers/Cat.hpp"

/**========================================================================
 *                      Constructors, destructor, overloads
 *========================================================================**/

Cat::Cat( void )
{
	this->_type = "Cat";
	std::cout << "Cat\t default constructor" << std::endl;
}

Cat::Cat( Cat const & other ) : Animal(other)
{
	this->_type = other._type;
	std::cout << "Cat\t copy constructor" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat\t\t destroyed" << std::endl;
}

Cat& Cat::operator=( Cat const & other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/*=========================================================================*/

void	Cat::makeSound( void ) const
{
	std::cout << "*** Miaou ! ***" << std::endl;
}