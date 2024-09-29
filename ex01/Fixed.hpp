/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:37:02 by amecani           #+#    #+#             */
/*   Updated: 2024/09/29 18:43:16 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);

#endif