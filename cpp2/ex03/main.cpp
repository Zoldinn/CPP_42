#include <iostream>
#include "Point.hpp"

int	main( void )
{
	// Triangle
	Point	a(0, 0);
	Point	b(5, 5);
	Point	c(10, -1);

	// Points that should be in the triangle
	Point	p1(1, 0);
	Point	p2(5, 1);
	Point	p3(7, 0);
	Point	p4(6.5f, 2.5f);
	Point	p5(9, -0.5f);

	// Points that should NOT be in the triangle
	Point	p6(10, 3);
	Point	p7(5, 5); // On a sommet
	Point	p8(2, 2); // On an arrete
	Point	p9(-1, 4);
	Point	p10(-5, -0.5f); // On an arrete

	Point	P[10] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};

	for (int i = 0; i < 10; i++)
	{
		if (bsp(a, b, c, P[i]) == true)
			std::cout << "p" << i << "is in the triangle" << std::endl;
		else
			std::cout << "p" << i << "is NOT in the triangle" << std::endl;
	}

	return 0;
}
