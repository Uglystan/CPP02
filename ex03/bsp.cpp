/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:36:10 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/24 09:37:08 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	Point::area(Point const& p1, Point const& p2, Point const& p3)
{
	float p1_x = p1.get_x();
	float p2_x = p2.get_x();
	float p3_x = p3.get_x();
	float p1_y = p1.get_y();
	float p2_y = p2.get_y();
	float p3_y = p3.get_y();

	return(0.5 * std::abs((p2_x - p1_x) * (p3_y - p1_y) - (p3_x - p1_x) * (p2_y - p1_y)));
}

bool	Point::mxp(Point const& a, Point const& b, Point const& point)
{
	float 	m = (b.get_y() - a.get_y()) / (b.get_x() - a.get_x());
	float 	p = a.get_y() - m * a.get_x();

	if (point.get_y() == m * point.get_x() + p)
		return (true);//sur arrete
	else
		return (false);
}

bool	Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (mxp(a, b, point) == true || mxp(a, c, point) == true || mxp(b, c, point) == true)
		return (false);

	float	areaABC = Point::area(a, b, c);
	float	areaABpoint = Point::area(a, b, point);
	float	areaACpoint = Point::area(a, c, point);
	float	areaBCpoint = Point::area(b, c, point);
	float	sommeArea;

	std::cout << areaABC << std::endl;
	std::cout << areaABpoint << std::endl;
	std::cout << areaACpoint << std::endl;
	std::cout << areaBCpoint << std::endl;
	sommeArea = areaABpoint + areaACpoint + areaBCpoint;

	return (std::abs(areaABC - sommeArea) < 1e-6);
}