/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:36:33 by amecani           #+#    #+#             */
/*   Updated: 2024/09/29 18:45:31 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operator called" << std::endl;
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
	_value = std::roundf(value * (1 << _fractionalBits));
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
