#include "Point.hpp"

/**========================================================================
 **                        Constructors/Destructor
 *========================================================================**/

Point::Point( void ) : _x(0), _y(0) {};
Point::~Point( void ) {};
Point::Point( Point const & cpy ) : _x(cpy._x), _y(cpy._y) {};
Point::Point( float const x, float const y ) : _x(x), _y(y) {};

/**========================================================================
 **                              Operators
 *========================================================================**/

Point&	Point::operator=( Point const & right ) 
{
	// if (this != &right)
	// {
	// 	this->_x = right._x;
	// 	this->_y = right._y;
	// }
	(void) right;
	return *this;
}

/**========================================================================
**                                Functions
 *========================================================================**/

Fixed	Point::get( char const what ) const
{
	if (what == 'x' || what == 'X')
		return this->_x;
	else if (what == 'y' || what == 'Y')
		return this->_y;
	std::cerr << "Error getting" << std::endl;
	return Fixed(0);
}