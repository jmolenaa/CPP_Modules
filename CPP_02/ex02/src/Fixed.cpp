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
//	std::cout << "Default constructor of Fixed class called\n";
}

Fixed::Fixed(int const val) {
//	std::cout << "Parameterized integer constructor of Fixed class called\n";
	this->_value = val << _fractional_bits;
}

Fixed::Fixed(float const val) {
//	std::cout << "Parameterized float constructor of Fixed class called\n";
	this->_value = (int)(val * (1 << _fractional_bits));
}

Fixed::Fixed(Fixed const &src) : _value(src._value) {
//	std::cout << "Copy constructor for Fixed class called\n";
}

Fixed::~Fixed() {
//	std::cout << "Destructor of Fixed class called\n";
}

Fixed&	Fixed::operator=(Fixed const &rhs) {
//	std::cout << "Assignment operator of Fixed class called\n";
	if (this == &rhs)
		return (*this);

	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed	temp;

	temp._value = this->_value + rhs._value;
	return (temp);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed	temp;

	temp._value = this->_value - rhs._value;
	return (temp);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed	temp;

	temp._value = (this->_value * rhs._value) >> _fractional_bits;
	return (temp);
}

Fixed Fixed::operator/(const Fixed &rhs) const {

	Fixed	temp;

	temp._value = (this->_value << _fractional_bits) / rhs._value;
	return (temp);

}

bool Fixed::operator>(const Fixed &rhs) const {
	return (this->_value > rhs._value);
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return (this->_value >= rhs._value);
}

bool Fixed::operator<(const Fixed &rhs) const {
	return (this->_value < rhs._value);
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(const Fixed &rhs) const {
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return (this->_value != rhs._value);
}

// so this is the prefix one, it needs to return a reference cause of this case
// ++(++(++fixed));, if we return a copy of an object (not a reference) we would be
// incrementing our actual object once, then increment the temporary object
// now we increment the original 3 times, same for --
Fixed& Fixed::operator++() {
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	temp = *this;

	++(*this);
	return (temp);
}

Fixed& Fixed::operator--() {
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	temp = *this;

	--(*this);
	return (temp);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2) {
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed const& Fixed::min(const Fixed &fix1, const Fixed &fix2) {
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2) {
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

Fixed const& Fixed::max(const Fixed &fix1, const Fixed &fix2) {
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

int Fixed::toInt() const {
	return (this->_value >> _fractional_bits);
}

float Fixed::toFloat() const {
	return ((float)this->_value / (1 << _fractional_bits));
}

int Fixed::getRawBits() const {
//	std::cout << "getRawBits called\n";
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
//	std::cout << "setRawBits called\n";
	this->_value = raw;
}

std::ostream&	operator<<(std::ostream& outstream, Fixed const & rhs){
	outstream << rhs.toFloat();
	return (outstream);
}
