#include "Animal.hpp"

/**========================================================================
 *                      Constructors, destructor, overloads
 *========================================================================**/

Animal::Animal( void )
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal( Animal const & other )
{
	*this = other;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal & Animal::operator=( Animal const & other )
{
	if (this != &other)
		*this = other;
	return *this;
}


