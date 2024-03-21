/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 20:55:30 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/02/04 20:55:30 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	test(float nr1, float nr2)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5.1f, 10.1f);

	Point point(nr1, nr2);
	std::cout << "\nTest for point:				(" << nr1 << " , " << nr2 << ")\n";
	std::cout << "Actual fixed point number:	(" << point.getX() << " , " << point.getY() << ")\n";
	std::cout << bsp(a, b, c, point) << "\n";

}

int main() {

	std::cout << std::boolalpha;
	std::cout << "Standard test with point in the triangle\n";
	test(5, 1);

	std::cout << "\n------------------------------------------------\nTesting vertexes\n";
	test(0, 0);
	test(10, 0);
	test(5.1f, 10.1f);

	std::cout << "\n------------------------------------------------\nTesting point edginess\n";
	test(5, 0);
	test(1.5f, 0);
	test(1.12321f, 0);
	test(9.123123f, 0);

	std::cout << "\n------------------------------------------------\nTesting very edge cases showing limits of fixed points\n";
	test(5, 0.01f);
	test(5, 0.001f);
	test(0, 0.001f);
	test(5, 0.0039f);
	test(5, 0.004f);


	return 0;
}

