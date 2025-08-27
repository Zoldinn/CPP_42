#include "../headers/AAnimal.hpp"

/**========================================================================
 *                      Constructors, destructor, overloads
 *========================================================================**/

AAnimal::AAnimal( void )
{
	this->_type = "...";
	std::cout << "Animal\t default constructor" << std::endl;
}

AAnimal::AAnimal( AAnimal const & other )
{
	this->_type = other._type;
	std::cout << "Animal\t copy constructor" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Animal\t destroyed" << std::endl;
}

AAnimal& AAnimal::operator=( AAnimal const & other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/*=========================================================================*/

std::string	AAnimal::getType( void ) const
{
	return this->_type;
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "*** Animal sound ***" << std::endl;
}
