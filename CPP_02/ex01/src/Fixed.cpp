/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 20:55:19 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/02/04 20:55:19 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor of Fixed class called\n";
}

Fixed::Fixed(Fixed const &src) : _value(src._value) {
	std::cout << "Copy constructor for Fixed class called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor of Fixed class called\n";
}

Fixed&	Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assignment operator of Fixed class called\n";
	if (this == &rhs)
		return (*this);

	this->_value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits called\n";
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits called\n";
	this->_value = raw;
}
