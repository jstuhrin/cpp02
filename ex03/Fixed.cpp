#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed() : raw(0)
{

}

Fixed::Fixed(int const value) : raw(value << Fixed::fractional_bits)
{

}

Fixed::Fixed(float const value) : raw(static_cast<int>(value * (1 << Fixed::fractional_bits)))
{

}

Fixed::Fixed(const Fixed& other) : raw(other.getRawBits())
{

}

Fixed::~Fixed()
{

}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
	{
		return (*this);
	}
	raw = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->raw) / (1 << Fixed::fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->raw / (1 << Fixed::fractional_bits));
}

std::string	Fixed::toBinStr(void) const
{
	unsigned int	mask = 1 << 31;
	std::string		bin_num;	

	for (int i = 31; i >= 0; i--)
	{
		if (i == 7)
		{
			bin_num.push_back('.');
		}
		bin_num.push_back((this->raw & mask) ? '1' : '0');
		mask >>= 1;
	}
	return (bin_num);
}

bool	Fixed::operator>(Fixed other) const
{
	return (this->raw > other.getRawBits() ? true : false);
}

bool	Fixed::operator<(Fixed other) const
{
	return (this->raw < other.getRawBits() ? true : false);
}

bool	Fixed::operator>=(Fixed other) const
{
	return (this->raw >= other.getRawBits() ? true : false);
}

bool	Fixed::operator<=(Fixed other) const
{
	return (this->raw <= other.getRawBits() ? true : false);
}

bool	Fixed::operator==(Fixed other) const
{
	return (this->raw == other.getRawBits() ? true : false);
}

bool	Fixed::operator!=(Fixed other) const
{
	return (this->raw != other.getRawBits() ? true : false);
}

Fixed	Fixed::operator+(Fixed other) const
{
	Fixed	temp;
	temp.setRawBits(this->raw + other.getRawBits());
	return(temp);
}

Fixed	Fixed::operator-(Fixed other) const
{
	Fixed	temp;
	temp.setRawBits(this->raw - other.getRawBits());
	return(temp);
}

Fixed	Fixed::operator*(Fixed other) const
{
	Fixed		temp;
	long long	wide;

	wide = static_cast<long long>(this->raw) * other.getRawBits();
	temp.setRawBits(static_cast<int>(wide >> Fixed::fractional_bits));
	return (temp);
}

Fixed	Fixed::operator/(Fixed other) const
{
	Fixed		temp;
	long long	wide;

	wide = static_cast<long long>(this->raw << Fixed::fractional_bits) / other.getRawBits();
	temp.setRawBits(static_cast<int>(wide));
	return (temp);
}

Fixed&	Fixed::operator++()
{
	this->raw++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->raw--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--*this;
	return (temp);
}

Fixed&	Fixed::min(Fixed& left, Fixed& right)
{
	return (left.getRawBits() <= right.getRawBits() ? left : right);
}

Fixed&	Fixed::max(Fixed& left, Fixed& right)
{
	return (left.getRawBits() >= right.getRawBits() ? left : right);
}

const Fixed&	Fixed::min(const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() <= right.getRawBits() ? left : right);
}
const Fixed&	Fixed::max(const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() >= right.getRawBits() ? left : right);
}

namespace
{
	int	invertBits(int number)
	{
		int				inverted = 0;
		unsigned int	mask = 1 << 31;

		for (int i = 0; i < 32; i++)
		{
			if ((number & mask) == 0)
			{
				inverted += 1;
			}
			if (i < 31)
			{
				inverted <<= 1;	
			}
			mask >>= 1;
		}
		return (inverted);
	}

	int	invertTwosComp(const Fixed& number)
	{
		int	invTwosComp = number.getRawBits();
		invTwosComp -= 1;
		invTwosComp = invertBits(invTwosComp) ;
		return (invTwosComp);
	}

	int	constructFracInt(const Fixed& number)
	{
		int	frac_digits[8] = {50000000, 25000000, 12500000, 6250000, 3125000, 1562500, 781250, 390625};
		int	frac_int = 0;
		int	raw = 0;

		if (number.getRawBits() >= 0)
		{
			raw = number.getRawBits();
		}
		else
		{
			raw = invertTwosComp(number);
		}
		for (int i = 7; i >= 0; i--)
		{
			if ((raw & 1) == 1)
			{
				frac_int += frac_digits[i];
			}
			raw >>= 1;
		}
		return (frac_int);
	}

	std::string	constructFracString(const Fixed& number)
	{
		std::string			temp;
		std::string			frac_str;
		std::ostringstream	oss;
		size_t				len;

		oss << constructFracInt(number);
		temp = oss.str();
		len = temp.length();
		for (size_t i = 0; i < (8 - len); i++)
		{
			frac_str.push_back('0');
		}
		frac_str.append(temp);
		return (frac_str);
	}

	size_t	measureLenFracPart(const std::string& frac_str)
	{
		int len = 7;

		while (len >= 0)
		{
			if (frac_str[len] != '0')
			{
				return (len += 1);
			}
			len--;
		}
		return (0);
	}
}

std::ostream& operator<<(std::ostream& os, const Fixed& number)
{
	std::string	frac_str = constructFracString(number);
	int			frac_str_len = measureLenFracPart(frac_str);

	if (frac_str_len == 0)
	{
		os << number.toInt();
		return (os);
	}
	if (number.getRawBits() < 0)
	{
		os << "-" << (number.toInt() * -1);
	}
	else
	{
		os << number.toInt();
	}
	os << "." << frac_str.substr(0, frac_str_len);
	return (os);
}
