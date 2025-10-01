#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed() : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : raw(value << this->fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : raw(static_cast<int>(value * (1 << this->fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : raw(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	raw = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& number)
{
	os << number.toFloat();
	return (os);
}
