/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:51:44 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/20 17:06:41 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <sstream>

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
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

#endif