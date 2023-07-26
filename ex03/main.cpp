/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:28:56 by lgirault          #+#    #+#             */
/*   Updated: 2023/07/24 09:37:45 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	Point a(-1, 1);
	Point b(2, 2);
	Point c(-4, 6);
	Point point(-2, 1.5);

	if (a.bsp(a, b, c, point) == true)
		std::cout << "Dedans" << std::endl;
	else
		std::cout << "Dehors" << std::endl;

	return 0;
}