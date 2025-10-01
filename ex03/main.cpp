#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	std::cout << "Point is outside of triangle, or on edge or vertex:" << std::endl;
	{
		Point	a(1, 1);
		Point	b(a);
		Point	c(a);
		Point	point(1, 1);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	{
		Point	a(1, 1);
		Point	b(2, 2);
		Point	c(3, 3);
		Point	point(2, 2);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	{
		Point	a(1, 1);
		Point	b(4, 2);
		Point	c(2, 4);
		Point	point(5, 5);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	{
		Point	a(-1, -1);
		Point	b(4.5f, 2.5f);
		Point	c(2.5f, 4.5f);
		Point	point(4.5f, 2.5f);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	{
		Point	a(-1, -1);
		Point	b(4.5f, -1);
		Point	c(2.5f, 4.5f);
		Point	point(2.43f, -1);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	std::cout << "Point is inside of triangle:" << std::endl;
	{
		Point	a(1.5f, 1.5f);
		Point	b(4, 2);
		Point	c(2, 4);
		Point	point(2, 2);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	{
		Point	a(-1, -1);
		Point	b(-4, -2);
		Point	c(-2, -4);
		Point	point(-1.5f, -1.9f);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	{
		Point	a(-1, -1);
		Point	b(4.5f, 2.5f);
		Point	c(2.5f, 4.5f);
		Point	point(0, 0);

		std::cout << bsp(a, b, c, point) << std::endl;
	}
	return (0);
}
