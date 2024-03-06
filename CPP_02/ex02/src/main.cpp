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

void	comparisons(float first, float second)
{
	Fixed a(first);
	Fixed b(second);
	std::cout << std::boolalpha;
	std::cout << "\nComparisons\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "<: " << (a < b);
	std::cout << "\n<=: " << (a <= b);
	std::cout << "\n>: " << (a > b);
	std::cout << "\n>=: " << (a >= b);
	std::cout << "\n==: " << (a == b);
	std::cout << "\n!=: " << (a != b);
	std::cout << "\n\n";
}

int main( void ) {
	std::cout << "Subject tests\n\n";
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}

	std::cout << "\n\nMy own stuff\n";
	comparisons(12.1f, 12.2f);
	comparisons(12.0f, 12.0f);
	comparisons(12.1235f, 12.1239f);

	return 0;
}

