#include "Fixed.hpp"
#include <math.h>

const int	Fixed::_bits = 8;

/**========================================================================
 *                        Constructors/Destructor
 *========================================================================**/

Fixed::Fixed( void ) : _fixed(0)										// Default
{
	return;
}

Fixed::Fixed( Fixed const & cpy )										// Copy
{
	*this = cpy;
}

Fixed::Fixed ( int const x )											// Int
{
	this->_fixed = x << _bits;
}

Fixed::Fixed ( float const x )											// Float
{
	this->_fixed = roundf(x * (1 << _bits));
}

Fixed::~Fixed( void )													// Destructor
{
	return;
}

/**========================================================================
 *                           Overloaded operators
 *========================================================================**/

std::ostream& operator<<( std::ostream& os, Fixed const & toOutput )	// <<
{
	os << toOutput.toFloat();
	return os;
}

Fixed&	Fixed::operator=( Fixed const & right )							// =
{
	if (this != &right)
		this->_fixed = right.getRawBits();
	return *this;
}

/**======================
 *    Arithmetics
 *========================**/

Fixed Fixed::operator+( Fixed const & right ) const						// +
{
	return Fixed(this->getRawBits() + right.getRawBits());
}

Fixed Fixed::operator-( Fixed const & right ) const						// -
{
	return Fixed(this->getRawBits() - right.getRawBits());
}

Fixed Fixed::operator*( Fixed const & right ) const						// *
{
	return Fixed(this->toFloat() * right.toFloat());
}

Fixed Fixed::operator/( Fixed const & right ) const						// /
{
	return Fixed(this->toFloat() / right.toFloat());
}

/**======================
 *    Incrementor/Decrementor
 *========================**/

Fixed&	Fixed::operator++( void )										// ++prefix
{
	this->_fixed++;
	return *this;
}

Fixed&	Fixed::operator--( void )										// --prefix
{
	this->_fixed--;
	return *this;
}

Fixed	Fixed::operator++( int )										// postfix++
{
	Fixed	old;

	old = *this;
	this->_fixed++;
	return old;
}

Fixed	Fixed::operator--( int )										// postfix--
{
	Fixed	old;

	old = *this;
	this->_fixed--;
	return old;
}

/**======================
 *    Comparators
 *========================**/

bool	Fixed::operator>( Fixed const & right ) const					// >
{
	return this->getRawBits() > right.getRawBits() ? 1 : 0;
}

bool	Fixed::operator<( Fixed const & right ) const					// <
{
	return this->getRawBits() < right.getRawBits() ? 1 : 0;
}

bool	Fixed::operator>=( Fixed const & right ) const					// >=
{
	return this->getRawBits() >= right.getRawBits() ? 1 : 0;
}

bool	Fixed::operator<=( Fixed const & right ) const					// <=
{
	return this->getRawBits() <= right.getRawBits() ? 1 : 0;
}

bool	Fixed::operator==( Fixed const & right ) const					// ==
{
	return this->getRawBits() == right.getRawBits() ? 1 : 0;
}

bool	Fixed::operator!=( Fixed const & right ) const					// !=
{
	return this->getRawBits() != right.getRawBits() ? 1 : 0;
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

Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	return a > b ? b : a;
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	return a < b ? b : a;
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b )
{
	return a > b ? b : a;
}

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b )
{
	return a < b ? b : a;
}
