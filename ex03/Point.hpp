/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:58:35 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/24 09:34:30 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <iostream>
#include "Fixed.hpp"

class	Point
{
	public :
		Point(void);
		Point(float const x, float const y);
		~Point(void);
		Point(Point const& substitue);
		Point&	operator=(Point const& substitue);
		static float	area(Point const& p1, Point const& p2, Point const& p3);
		static bool	mxp(Point const& a, Point const& b, Point const& point);
		bool	bsp(Point const a, Point const b, Point const c, Point const point);
		float	get_x(void) const;
		float	get_y(void) const;
	
	private :
		Fixed _x;
		Fixed _y;
};

#endif