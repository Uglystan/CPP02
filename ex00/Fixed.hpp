/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:51:44 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/21 10:10:49 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private :
		int	_rawBits;
		static int const	_nBitFrac;

	public :
		Fixed(void);
		Fixed(Fixed const& substitue);
		~Fixed(void);
		Fixed&	operator=(Fixed const& substitue);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif