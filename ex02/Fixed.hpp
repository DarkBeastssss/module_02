/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:37:02 by amecani           #+#    #+#             */
/*   Updated: 2024/09/29 20:10:40 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <sstream>

class Fixed
{
	public:
		Fixed(void);							// Default constructor
		Fixed(const Fixed &src);				// Copy constructor
		Fixed	&operator=(const Fixed &src);	// Assignment operator
		~Fixed(void);							// Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(const int value);
		Fixed(const float value);

		float	toFloat(void) const;
		int		toInt(void) const;

		// comparison operators
		bool	operator >(const Fixed &src) const;
		bool	operator <(const Fixed &src) const;
		bool	operator >=(const Fixed &src) const;
		bool	operator <=(const Fixed &src) const;
		bool	operator ==(const Fixed &src) const;
		bool	operator !=(const Fixed &src) const;

		// arithmetic operators
		Fixed	operator +(const Fixed &src) const;
		Fixed	operator -(const Fixed &src) const;
		Fixed	operator *(const Fixed &src) const;
		Fixed	operator /(const Fixed &src) const;
		
		// increment and decrement operators
		Fixed	&operator ++(void);
		Fixed	operator ++(int);
		Fixed	&operator --(void);
		Fixed	operator --(int);

		// min and max functions
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);

#endif