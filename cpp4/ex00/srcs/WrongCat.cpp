#include "../headers/WrongCat.hpp"

/**========================================================================
 *                       Constructors, destructor, overload
 *========================================================================**/

WrongCat::WrongCat( void )
{
	std::cout << "WrongCat\t default constructor" << std::endl;
}

WrongCat::WrongCat( WrongCat const & other ) : WrongAnimal(other)
{
	this->_type = other._type;
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat\t destroyed" << std::endl;
}

WrongCat&	WrongCat::operator=( WrongCat const & other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/*=========================================================================*/

void	WrongCat::makeSound( void ) const
{
	std::cout << "*** WrongCat miow miow ***" << std::endl;
}
