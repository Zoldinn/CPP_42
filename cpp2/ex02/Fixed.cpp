#include "Fixed.hpp"
#include <math.h>

const int	Fixed::_bits = 8;

/**========================================================================
 *                   Constructors/Destructor/Operator overload
 *========================================================================**/

Fixed::Fixed( void ) : _fixed(0)									//! Default
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & cpy)									//! Copy
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed ( int const x )										//! Int
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = x << _bits;
}

Fixed::Fixed ( float const x )										//! Float
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(x * (1 << _bits));
}

Fixed::~Fixed( void )												//! Destructor
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const & other)						//! =
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_fixed = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, Fixed const & toOutput )	//! <<
{
	os << toOutput.toFloat();
	return os;
}

/**========================================================================
 *                               Functions
 *========================================================================**/

int		Fixed::getRawBits( void ) const
{
	return this->_fixed;
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed >> _bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed / (1 << _bits));
}
