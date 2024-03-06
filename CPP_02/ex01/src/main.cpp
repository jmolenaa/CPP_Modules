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
#include "Fixed.hpp"

int	main() {
	std::cout << "Tests from subject\n\n";

	{
		Fixed a;
		Fixed const b(10);
		Fixed const c(42.42f);
		Fixed const d(b);

		a = Fixed(1234.4321f);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}

	std::cout << "\n\nMy own stuff to show what happens\n";
	{
		std::cout << std::fixed;
		std::cout << "Truncating of big integers above 24 bits, we have a smaller range\n";
		std::cout << "Constructing integer 8388607\n";
		Fixed a(8388607);
		std::cout << "a as integer: " << a.toInt() << "\na as float: " << a.toFloat() << "\n\n";

		std::cout << "Constructing integer 8388608\n";
		Fixed b(8388608);
		std::cout << "a as integer: " << b.toInt() << "\na as float: " << b.toFloat() << "\n\n";
	}
	{
		std::cout << std::defaultfloat;
		std::cout << "\n\nShowing the least significant bit for the float precision\n";

		std::cout << "Constructing float a 0\n";
		Fixed a (0);
		std::cout << "a as float: " << a.toFloat() << "\n\n";

		std::cout << "Constructing float b 0.00390624\n";
		Fixed b (0.00390624f);
		std::cout << "b as float: " << b.toFloat() << "\n\n";

		std::cout << "Constructing float c 0.00390625\n";
		Fixed c (0.00390625f);
		std::cout << "c as float: " << c.toFloat() << "\n\n";

	}

	{
		std::cout << "\n\n Showing how useless the setRawBits function is\n";
		std::cout << "Constructing fixed point 4.32 and then setting raw bits to 1\n";
		Fixed a(4.32f);
		std::cout << "a as integer: " << a.toInt() << "\na as float: " << a.toFloat() << "\n\n";
		a.setRawBits(1);
		std::cout << "a as integer: " << a.toInt() << "\na as float: " << a.toFloat() << "\n\n";
	}
	return 0;
}

