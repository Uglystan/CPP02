/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:01:14 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/24 09:38:38 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "Constructor Point called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	std::cout << "Constructor with parametre Point called" << std::endl;
}

Point::Point(Point const& substitue)
{
	std::cout << "Copie constructor Point called" << std::endl;
	this->_x = substitue._x;
	this->_y = substitue._y;
}

Point&	Point::operator=(Point const& substitue)
{
	if (this != &substitue)
	{
		this->_x = substitue._x;
		this->_y = substitue._y;
	}
	return (*this);
}

Point::~Point(void)
{
	std::cout << "Destructor Point called" << std::endl;
}

float	Point::get_x(void) const
{
	return (_x.toFloat());
}

float	Point::get_y(void) const
{
	return (_y.toFloat());
}
