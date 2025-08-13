#ifndef POINT_HPP
# define POINT_HPP

 #include <iostream>
 #include "Fixed.hpp"

 class Point
 {
	public:
		Point( void );
		Point( Point const & cpy );
		~Point( void );
		Point( float const x, float const y );

		Point&	operator=( Point const & right );

		bool	bsp( Point const a, Point const b, Point const c, Point const point);

	private:
		Fixed const	_x;
		Fixed const	_y;
 };

#endif