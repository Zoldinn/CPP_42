#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog( Dog const & other )
{
	*this = other;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog destroyed" << std::endl;

}

Dog & Dog::operator=( Dog const & other )
{
	if (this != &other)
	{
		// copy attributes
	}
	return *this;
}