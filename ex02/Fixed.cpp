/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:57:32 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/21 16:54:45 by lgirault         ###   ########.fr       */
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
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

Fixed::Fixed(int const toFixedPoint) : _rawBits(0)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = toFixedPoint << _nBitFrac;
}

/*---------------------------------EX01-------------------------------------*/

Fixed::Fixed(float const toFixedPoint) : _rawBits(0)
{
	std::cout << "Float constructor called" << std::endl;
	/*En général, multiplier un nombre binaire par une puissance de 2 (2^n)
	est équivalent à effectuer un décalage de bits de n positions vers
	la gauche, ce qui est un moyen efficace de réaliser des multiplications
	par des puissances de 2 en binaire.*/
	_rawBits = (roundf(toFixedPoint * (1 << _nBitFrac)));//*128 reviens a decaler les bits de 7 position vers la gauche
}

float	Fixed::toFloat(void) const
{
	/*Diviser un nombre par 128 revient a decaler les bits de 8 position
	pour un nombre flottant c'est l'exposant qui change*/
	return ((float)_rawBits / (float)(1 << _nBitFrac));
}


int	Fixed::toInt(void) const
{
	return (_rawBits >> _nBitFrac);
}

std::ostream&	operator<<(std::ostream& flux, Fixed const& fixed)
{
	flux << fixed.toFloat();
	return (flux);
}

/*---------------------------------EX02-------------------------------------*/

bool	Fixed::operator>(Fixed const& b) const
{
	return (this->_rawBits > b._rawBits);
}

bool	Fixed::operator<(Fixed const& b) const
{
	return (this->_rawBits < b._rawBits);
}

bool	Fixed::operator>=(Fixed const& b) const
{
	return (this->_rawBits >= b._rawBits);
}

bool	Fixed::operator<=(Fixed const& b) const
{
	return (this->_rawBits <= b._rawBits);
}

bool	Fixed::operator==(Fixed const& b) const
{
	return (this->_rawBits == b._rawBits);
}

bool	Fixed::operator!=(Fixed const& b) const
{
	return (this->_rawBits != b._rawBits);
}

Fixed	Fixed::operator+(Fixed const& b) const
{
	Fixed	result;
	result._rawBits = this->_rawBits + b._rawBits;
	return (result);
}

Fixed	Fixed::operator-(Fixed const& b) const
{
	Fixed	result;
	result._rawBits = this->_rawBits - b._rawBits;
	return (result);
}

Fixed	Fixed::operator*(Fixed const& b) const
{
	return (this->toFloat() * b.toFloat());
}

Fixed	Fixed::operator/(Fixed const& b) const
{
	if (this->_rawBits != 0 && b._rawBits != 0)
		return (this->toFloat() / b.toFloat());
	else
	{
		std::cout << "Can't divide by 0" << std::endl;
		return (*this);
	}
}

Fixed&	Fixed::operator++(void)//prefixe
{
	_rawBits++;
	return (*this);
}

Fixed const	Fixed::operator++(int)//postfixe
{
	Fixed copie(*this);
	this->_rawBits++;
	return (copie);
}

Fixed& Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed const	Fixed::operator--(int)
{
	Fixed	copie(this->_rawBits);
	copie._rawBits--;
	return (copie);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a < b) ? b : a);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	return ((a < b) ? b : a);
}

// float	Fixed::toFloat(void) const
// {
// 	std::stringstream	stream;
// 	std::stringstream	stream1;
// 	std::string	str_entPart;
// 	std::string	str_fracPart;
// 	int	int_entPart;
// 	int	int_fracPart;
// 	float	toFloat;
	
// 	int_entPart = _rawBits >> _nBitFrac;
// 	int_fracPart = _rawBits & 255;
// 	// std::cout << int_fracPart << std::endl;
// 	stream << std::fixed << int_entPart;
// 	str_entPart = stream.str();
// 	stream1 << std::fixed << int_fracPart;
// 	str_fracPart = stream1.str();
// 	str_entPart.append(1, '.');
// 	str_entPart += str_fracPart;
// 	toFloat = atof(str_entPart.c_str());
// 	return (toFloat);
// }

// Fixed::Fixed(float const toFixedPoint) : _rawBits(0)
// {
// 	std::cout << "Float constructor called" << std::endl;
// 	std::stringstream	stream;
// 	std::string		str_fracPart;
// 	int			int_fracPart = 0;

// 	// if (roundf(toFixedPoint) < toFixedPoint)
// 	// 	stream << std::fixed << (toFixedPoint - roundf(toFixedPoint));
// 	// else
// 	// 	stream << std::fixed << (toFixedPoint - (roundf(toFixedPoint) - 1));
// 	stream << std::fixed << std::setprecision(3) << (toFixedPoint - static_cast<int>(toFixedPoint));
// 	std::cout << toFixedPoint - static_cast<int>(toFixedPoint) << std::endl;
// 	str_fracPart = stream.str();
// 	str_fracPart.erase(0, 2);
// 	int_fracPart = atoi(str_fracPart.c_str());
// 	if (int_fracPart > 255)
// 		std::cout << std::fixed << std::setprecision(2);
// 	else
// 		std::cout << std::fixed << std::setprecision(3);
// 	while (int_fracPart > 255)
// 		int_fracPart /= 10;
// 	if (roundf(toFixedPoint) < toFixedPoint)
// 		_rawBits = (int)(roundf(toFixedPoint)) << (_nBitFrac);
// 	else
// 		_rawBits = (int)(roundf(toFixedPoint) - 1) << (_nBitFrac);
// 	_rawBits = _rawBits | int_fracPart;
// }