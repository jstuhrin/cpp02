#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
	Fixed&	operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& number);

#endif