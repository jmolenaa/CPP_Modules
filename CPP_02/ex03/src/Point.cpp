/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 09:16:59 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 09:16:59 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0){
	std::cout << "Default constructor called\n";
}

Point::Point(const Point &src) : _x(src._x), _y(src._y){
	std::cout << "Copy constructor called\n";
}

Point::Point(const float a, const float b) : _x(a), _y(b){
	std::cout << "Parameterized constructor called\n";
}

Point::~Point() {
	std::cout << "Destructor called\n";
}

Point &Point::operator=(const Point &rhs) {
	std::cerr << "Assignment operator called, doesn't do anything you dummy\n";
	(void)rhs;
	return (*this);
}
