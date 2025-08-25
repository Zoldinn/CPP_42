#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat( Cat const & other )
{
	*this = other;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat destroyed" << std::endl;

}

Cat & Cat::operator=( Cat const & other )
{
	if (this != &other)
	{
		// copy attributes
	}
	return *this;
}