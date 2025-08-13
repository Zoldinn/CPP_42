#include "Point.hpp"

/**========================================================================
 **                        Constructors/Destructor
 *========================================================================**/

Point::Point( void ) : _x(0), _y(0) {};
Point::~Point( void ) {};
Point::Point( Point const & cpy ) {*this = cpy;};
Point::Point( float const x, float const y ) : _x(x), _y(y) {};

/**========================================================================
 **                              Operators
 *========================================================================**/

Point&	Point::operator=( Point const & right )
{
	if (this != &right)
		*this = right;
	return *this;
}


