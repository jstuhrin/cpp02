#include "Fixed.hpp"

int main(void)
{
	{
		std::cout << "Testing min and max:" << std::endl;
		Fixed a(2.5f);
		Fixed b(6);
		Fixed c(b);

		std::cout << Fixed::max(a,b) << std::endl;
		std::cout << Fixed::min(a,b) << std::endl;
		std::cout << Fixed::max(a,a) << std::endl;
		std::cout << Fixed::min(b,c) << std::endl;
	}
	{
		std::cout << "Testing const min and const max:" << std::endl;
		const Fixed a(2.5f);
		const Fixed b(6);
		const Fixed c(b);

		std::cout << Fixed::max(a,b) << std::endl;
		std::cout << Fixed::min(a,b) << std::endl;
		std::cout << Fixed::max(a,a) << std::endl;
		std::cout << Fixed::min(b,c) << std::endl;
	}
	{
		std::cout << "\nTesting increment and decrement operators:" << std::endl;
		Fixed a(1);
		Fixed b(-1);

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << --a << std::endl;
		std::cout << b << std::endl;
		std::cout << --b << std::endl;
		std::cout << b << std::endl;
		std::cout << b-- << std::endl;
		std::cout << b << std::endl;
		std::cout << ++b << std::endl;
		std::cout << ++b << std::endl;
	}
	{
		std::cout << "\nTesting comparison operators:" << std::endl;
		Fixed a(1);
		Fixed b(-1);

		std::cout << a << " > " << b << ": " << ((a > b) ? "true" : "false") << std::endl;
		std::cout << a << " < " << b << ": " << ((a < b) ? "true" : "false") << std::endl;
		std::cout << a << " >= " << b << ": " << ((a >= b) ? "true" : "false") << std::endl;
		std::cout << a << " <= " << b << ": " << ((a <= b) ? "true" : "false") << std::endl;
		std::cout << a << " == " << b << ": " << ((a == b) ? "true" : "false") << std::endl;
		std::cout << a << " != " << b << ": " << ((a != b) ? "true" : "false") << std::endl;
		std::cout << a << " > " << a << ": " << ((a > a) ? "true" : "false") << std::endl;
		std::cout << a << " < " << a << ": " << ((a < a) ? "true" : "false") << std::endl;
		std::cout << a << " >= " << a << ": " << ((a >= a) ? "true" : "false") << std::endl;
		std::cout << a << " <= " << a << ": " << ((a <= a) ? "true" : "false") << std::endl;
		std::cout << a << " == " << a << ": " << ((a == a) ? "true" : "false") << std::endl;
		std::cout << a << " != " << a << ": " << ((a != a) ? "true" : "false") << std::endl;
	}
	{
		std::cout << "\nTesting arithmetical operators:" << std::endl;
		Fixed a(1);
		Fixed b(2);
		Fixed c(100);
		Fixed d(11);

		std::cout << a << " + " << b << " = " << a + b << std::endl;
		std::cout << a << " - " << b << " = " << a - b << std::endl;
		std::cout << a << " * " << b << " = " << a * b << std::endl;
		std::cout << a << " / " << b << " = " << a / b << std::endl;

		// std::cout << c * d / d << std::endl;
		// std::cout << a / (a + b) << std::endl;
		// std::cout << a / (b + b) << std::endl;
		// std::cout << (a / (b + b)) * (b + b) << std::endl;
	}
	{
		std::cout << "\nTesting edge cases:" << std::endl;
		Fixed a(0.00390625f);
		Fixed b(-0.00390625f);
		Fixed c(8388607);
		Fixed d(-8388608);
		Fixed e(8388607 / 2);
		Fixed f(-8388608 / 2);

		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << b << std::endl;
		std::cout << ++b << std::endl;

		std::cout << "FIXED_MAX:      " << c << std::endl;
		std::cout << "FIXED_MAX + 1: " << (c + 1) << std::endl;
		std::cout << "FIXED_MIN:     " << d << std::endl;
		std::cout << "FIXED_MIN - 1:  " << (d - 1) << std::endl;

		std::cout << "FIXED_MAX / 2:  " << e << std::endl;
		e = e * 2;
		std::cout << "          * 2:  " << e << std::endl;

		std::cout << "FIXED_MIN / 2: " << f << std::endl;
		f = f * 2;
		std::cout << "          * 2: " << f << std::endl;
	}
	// {
	// 	Fixed	test(8388607.5f);
	// 	std::cout << "test:                      " << test.toBinStr() << "\n";
	// 	std::cout << "        as fixed:          " << test << "\n";
	// 	std::cout << "        as int:            " << test.toInt() << "\n";
	// 	std::cout << "        as float:          " << std::setprecision(10) << test.toFloat() << "\n";
	// 	std::cout << std::endl;

	// 	for (int i = 0; i < 256; i++)
	// 	{
	// 		++test;
	// 		std::cout << "++test:                    " << test.toBinStr() << "\n";
	// 		std::cout << "        as fixed:          " << test << "\n";
	// 		std::cout << "        as int:            " << test.toInt() << "\n";
	// 		std::cout << "        as float:          " << test.toFloat() << "\n";
	// 		std::cout << std::endl;
	// 	}
	// }
	// {
	// 	Fixed a(-8388607.99609375f) ;
	// 	std::cout << "initialized fixed number with:             -8388607.99609375f\n";
	// 	std::cout << "fixed, set with float:                     " << a << "\n";
	// 	std::cout << "binary, set with float:                    " << a.toBinStr() << "\n";
	// 	std::cout << "\nprinting (-8388607.99609375f) as float:    " << std::setprecision(10) << (-8388607.99609375f) << "\n\n";
	// 	a.setRawBits(-2147483647);
	// 	std::cout << "set raw bits of fixed number with;         -2147483647\n";
	// 	std::cout << "Fixed, set with raw int:                   " << a << "\n";
	// 	std::cout << "binary, set with raw int:                  " << a.toBinStr() << "\n";
	// 	std::cout << "fixed, converted to float:                 " << a.toFloat() << "\n";
	// }
	return (0);
}
