#include "../headers/WrongAnimal.hpp"

/**========================================================================
 *                   Constructors, destructor, overload
 *========================================================================**/

WrongAnimal::WrongAnimal( void )
{
	std::cout << "WrongAnimal\t default constructor" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other )
{
	this->_type = other._type;
	std::cout << "WrongAnimal\t copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal\t destroyed" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( WrongAnimal const & other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/*=========================================================================*/


void			WrongAnimal::makeSound( void ) const
{
	std::cout << "*** WrongAnimal sound ***" << std::endl; 
}