/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 09:32:15 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 09:32:15 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

float	getAngle(Point& v1, Point& v2){

	float	dotProduct = v1.getX().toFloat() * v2.getX().toFloat() + v1.getY().toFloat() * v2.getY().toFloat();
	float	magnitudeV1 = std::sqrt(v1.getX().toFloat() * v1.getX().toFloat() + v1.getY().toFloat() * v1.getY().toFloat());
	float	magnitudeV2 = std::sqrt(v2.getX().toFloat() * v2.getX().toFloat() + v2.getY().toFloat() * v2.getY().toFloat());

	float	angle = std::acos(dotProduct / magnitudeV1 / magnitudeV2);

	angle = angle * 180 / M_PI;

	return (angle);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){

	if (a == point || b == point || c == point) {
		std::cout << "Point is one of the vertexes\n";
		return (false);
	}

	Point	vector1(a.getX().toFloat() - point.getX().toFloat(), a.getY().toFloat() - point.getY().toFloat());
	Point	vector2(b.getX().toFloat() - point.getX().toFloat(), b.getY().toFloat() - point.getY().toFloat());
	Point	vector3(c.getX().toFloat() - point.getX().toFloat(), c.getY().toFloat() - point.getY().toFloat());

	float	angle1 = getAngle(vector1, vector2);
	float	angle2 = getAngle(vector1, vector3);
	float	angle3 = getAngle(vector2, vector3);

	if (angle1 == 180 || angle2 == 180 || angle3 == 180) {
		std::cout << "The point is on edge\n";
		return (false);
	}

	float	totalAngle = roundf(angle1 + angle2 + angle3);

	if (totalAngle != 360){
		std::cout << "Point is outside the triangle\n";
		return (false);
	}
	std::cout << "Point is inside the triangle\n";
	return (true);
}
