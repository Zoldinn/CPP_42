#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed( void ) : _fixed(0)									// Default
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & cpy)									// Copy
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed( void )												// Destructor
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const & other)						// =
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_fixed = other.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}
