/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:36:33 by amecani           #+#    #+#             */
/*   Updated: 2024/09/29 20:13:41 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	_value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EX01 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EX02 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// comparison operators

bool	Fixed::operator>(const Fixed &src) const
{
	return (_value > src.getRawBits());
}

bool	Fixed::operator<(const Fixed &src) const
{
	return (_value < src.getRawBits());
}

bool	Fixed::operator>=(const Fixed &src) const
{
	return (_value >= src.getRawBits());
}

bool	Fixed::operator<=(const Fixed &src) const
{
	return (_value <= src.getRawBits());
}

bool	Fixed::operator==(const Fixed &src) const
{
	return (_value == src.getRawBits());
}

bool	Fixed::operator!=(const Fixed &src) const
{
	return (_value != src.getRawBits());
}

// arithmetic operators

Fixed	Fixed::operator+(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits(_value + src.getRawBits());
	return (ret);
}


Fixed	Fixed::operator-(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits(_value - src.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits((_value * src.getRawBits()) >> _fractionalBits);
	return (ret);
}


Fixed	Fixed::operator/(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits((_value << _fractionalBits) / src.getRawBits());
	return (ret);
}

// increment and decrement operators

Fixed	&Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);

	_value++;
	return (ret);
}

Fixed	&Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);

	_value--;
	return (ret);
}

// min and max functions

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
