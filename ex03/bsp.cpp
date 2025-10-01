#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	getCrossProduct(const Point& p1, const Point& p2, const Point& point)
{
	return(((point.getX() - p1.getX()) * (p2.getY() - p1.getY()))
			- ((p2.getX() - p1.getX()) * (point.getY() - p1.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	cross1 = getCrossProduct(a, b, point);
	Fixed	cross2 = getCrossProduct(b, c, point);
	Fixed	cross3 = getCrossProduct(c, a, point);
	// bool	neg = cross1 < 0 || cross2 < 0 || cross3 < 0;
	// bool	pos = cross1 > 0 || cross2 > 0 || cross3 > 0;
	// bool	zero = cross1 == 0 || cross2 == 0 || cross3 == 0;
	// bool	pointIsInside = !((neg && pos) || zero);
	// return (pointIsInside);
	if (cross1 < 0 && cross2 < 0 && cross3 < 0)
	{
		return (true);
	}
	if (cross1 > 0 && cross2 > 0 && cross3 > 0)
	{
		return (true);
	}
	return (false);
}
