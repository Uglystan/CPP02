/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:57:32 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/21 10:10:45 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static int const _nBitFrac = 8;

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Fixed called" << std::endl;
}

Fixed::Fixed(Fixed const& substitue)
{
	std::cout << "Copie constructor called" << std::endl;
	_rawBits = substitue.getRawBits();
	return ;
}

Fixed&	Fixed::operator=(Fixed const& substitue)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &substitue)
		this->_rawBits = substitue.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}