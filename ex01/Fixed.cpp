/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:57:32 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/20 19:59:43 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_nBitFrac = 8;

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const& substitue) : _rawBits(0)
{
	std::cout << "Copie constructor called" << std::endl;
	_rawBits = substitue.getRawBits();
	return ;
}

Fixed::Fixed(int const toFixedPoint) : _rawBits(0)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = toFixedPoint << _nBitFrac;
}

Fixed::Fixed(float const toFixedPoint) : _rawBits(0)
{
	std::cout << "Float constructor called" << std::endl;
	std::stringstream	stream;
	std::string		str_fracPart;
	int			int_fracPart = 0;

	// if (roundf(toFixedPoint) < toFixedPoint)
	// 	stream << std::fixed << (toFixedPoint - roundf(toFixedPoint));
	// else
	// 	stream << std::fixed << (toFixedPoint - (roundf(toFixedPoint) - 1));
	stream << std::fixed << std::setprecision(3) << (toFixedPoint - std::floor(toFixedPoint));
	str_fracPart = stream.str();
	str_fracPart.erase(0, 2);
	int_fracPart = atoi(str_fracPart.c_str());
	if (int_fracPart > 255)
		std::cout << std::fixed << std::setprecision(2);
	else
		std::cout << std::fixed << std::setprecision(3);
	while (int_fracPart > 255)
		int_fracPart /= 10;
	if (roundf(toFixedPoint) < toFixedPoint)
		_rawBits = (int)(roundf(toFixedPoint)) << (_nBitFrac);
	else
		_rawBits = (int)(roundf(toFixedPoint) - 1) << (_nBitFrac);
	_rawBits = _rawBits | int_fracPart;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Fixed called" << std::endl;
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

float	Fixed::toFloat(void) const
{
	std::stringstream	stream;
	std::stringstream	stream1;
	std::string	str_entPart;
	std::string	str_fracPart;
	int	int_entPart;
	int	int_fracPart;
	float	toFloat;
	
	int_entPart = _rawBits >> _nBitFrac;
	int_fracPart = _rawBits & 255;
	stream << std::fixed << int_entPart;
	str_entPart = stream.str();
	stream1 << std::fixed << int_fracPart;
	str_fracPart = stream1.str();
	str_entPart.append(1, '.');
	str_entPart += str_fracPart;
	toFloat = atof(str_entPart.c_str());
	return (toFloat);
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _nBitFrac);
}

// std::ostream&	operator<<(std::ostream& flux, Fixed const& fixed)
// {
// 	flux << fixed.toFloat();
// 	return (flux);
// }