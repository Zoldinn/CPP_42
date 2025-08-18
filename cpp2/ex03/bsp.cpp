#include "Point.hpp"

// TotalArea = ( (yB​−yC​)*(xA​−xC​) + (xC​−xB​)*(yA​−yC​) )
// α = (yB​−yC​)(xP​−xC​)+(xC​−xB​)(yP​−yC​) / TotalArea
// β = (yC​−yA​)(xP​−xA​)+(xA​−xC​)(yP​−yA​) / TotalArea
// γ = 1 − α − β 

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea( ((b.get('y') - c.get('y')) * (a.get('x') - c.get('x'))) + ((c.get('x') - b.get('x')) * (a.get('y') - c.get('y'))) );
	Fixed	epsilon(Fixed(0) / 512);
	if (totalArea == epsilon)
		return false;

	Fixed	alpha( (((b.get('y') - c.get('y')) * (point.get('x') - c.get('x'))) + ((c.get('x') - b.get('x')) * (point.get('y') - c.get('y')))) / totalArea);
	Fixed	beta( (((c.get('y') - a.get('y')) * (point.get('x') - a.get('x'))) + ((a.get('x') - c.get('x')) * (point.get('y') - a.get('y')))) / totalArea);
	Fixed	gamma( Fixed(1) - alpha - beta );

	if (alpha > epsilon && beta > epsilon && gamma > epsilon)
		return true;
	return false;
}
