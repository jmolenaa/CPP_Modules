/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 09:17:02 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 09:17:02 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
public:
	// Default
	Point();
	// Parameterized constr
	Point(float const a, float const b);
	// Copy constr
	Point(Point const& src);
	// Assignment operator overload
	Point&	operator=(Point const& rhs);
	// Destructor
	~Point();

private:
	Fixed const	_x;
	Fixed const	_y;
};


#endif
