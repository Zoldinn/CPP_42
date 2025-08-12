#include "Fixed.hpp"

const int	Fixed::_bits = 8;

/**========================================================================
 *                   Constructors/Destructor/Operator
 *========================================================================**/

Fixed::Fixed( void ) : _fixed(0)									// Default
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & cpy)									// Copy
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed ( const int x )
{

	this->setRawBits(x);
	this->toInt();
}

Fixed::Fixed ( const float x )
{
	this->setRawBits(x);
	this->toFloat();
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

/**========================================================================
 *                               Functions
 *========================================================================**/

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

int	Fixed::toInt( void ) const
{
	int	res;
	int	mantissa;

	mantissa = 2;
	for (int i = 0; i < _bits; i++)
		mantissa *= 2;

	res = this->getRawBits() / mantissa;
	return res;
}

float	Fixed::toFloat( void ) const
{
	float	res;
	int		mantissa;

	mantissa = 2;
	for (int i = 0; i < _bits; i++)
		mantissa *= 2;

	res = this->getRawBits() / mantissa;
	return res;
}
