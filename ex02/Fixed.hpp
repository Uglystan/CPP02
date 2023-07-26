/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:51:44 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/21 16:18:53 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

class	Fixed
{
	private :
		int	_rawBits;
		static int const	_nBitFrac;

	public :
		Fixed(void);
		Fixed(Fixed const& substitue);
		Fixed(int const toFixedPoint);
		Fixed(float const toFixedPoint);
		~Fixed(void);
		Fixed&	operator=(Fixed const& substitue);
		bool	operator>(Fixed const& b) const;
		bool	operator<(Fixed const& b) const;
		bool	operator>=(Fixed const& b) const;
		bool	operator<=(Fixed const& b) const;
		bool	operator==(Fixed const& b) const;
		bool	operator!=(Fixed const& b) const;
		Fixed	operator+(Fixed const& b) const;
		Fixed	operator-(Fixed const& b) const;
		Fixed	operator*(Fixed const& b) const;
		Fixed	operator/(Fixed const& b) const;
		Fixed&	operator++(void);
		Fixed const	operator++(int);
		Fixed&	operator--(void);
		Fixed const	operator--(int);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);
};

std::ostream&	operator<<(std::ostream& flux, Fixed const& fixed);

#endif