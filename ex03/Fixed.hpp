#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>

class	Fixed
{
private:
	int					raw;
	static const int	fractional_bits;

public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed&				operator=(const Fixed& other);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	std::string			toBinStr(void) const;

	bool				operator>(Fixed other) const;
	bool				operator<(Fixed other) const;
	bool				operator>=(Fixed other) const;
	bool				operator<=(Fixed other) const;
	bool				operator==(Fixed other) const;
	bool				operator!=(Fixed other) const;

	Fixed				operator+(Fixed other) const;
	Fixed				operator-(Fixed other) const;
	Fixed				operator*(Fixed other) const;
	Fixed				operator/(Fixed other) const;

	Fixed&				operator++();
	Fixed				operator++(int);
	Fixed&				operator--();
	Fixed				operator--(int);

	static Fixed&		min(Fixed& left, Fixed& right);
	static Fixed&		max(Fixed& left, Fixed& right);
	static const Fixed&	min(const Fixed& left, const Fixed& right);
	static const Fixed&	max(const Fixed& left, const Fixed& right);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& number);

#endif
