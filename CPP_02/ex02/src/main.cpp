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
	Fixed	a(first);
	Fixed	b(second);

	std::cout << std::boolalpha;
	std::cout << "\nComparisons\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << "<: " << (a < b);
	std::cout << "\n<=: " << (a <= b);
	std::cout << "\n>: " << (a > b);
	std::cout << "\n>=: " << (a >= b);
	std::cout << "\n==: " << (a == b);
	std::cout << "\n!=: " << (a != b);
	std::cout << "\n\n";
}

void	comparisons(int first, int second)
{
	Fixed	a(first);
	Fixed	b(second);

	std::cout << std::boolalpha;
	std::cout << "\nComparisons\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << "<: " << (a < b);
	std::cout << "\n<=: " << (a <= b);
	std::cout << "\n>: " << (a > b);
	std::cout << "\n>=: " << (a >= b);
	std::cout << "\n==: " << (a == b);
	std::cout << "\n!=: " << (a != b);
	std::cout << "\n\n";
}

void	minAndMaxConst(float first, float second){
	Fixed const	a(first);
	Fixed const	b(second);

	std::cout << "\nMin and max const\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << "min: " << Fixed::min(a, b) << "\n";
	std::cout << "max: " << Fixed::max(a, b) << "\n";

}

void	minAndMaxConst(int first, int second){
	Fixed const	a(first);
	Fixed const	b(second);

	std::cout << "\nMin and max const\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << "min: " << Fixed::min(a, b) << "\n";
	std::cout << "max: " << Fixed::max(a, b) << "\n";

}

void	minAndMax(float first, float second)
{
	Fixed	a(first);
	Fixed	b(second);

	std::cout << "\nMin and max\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << "min: " << Fixed::min(a, b) << "\n";
	std::cout << "max: " << Fixed::max(a, b) << "\n";
}

void	minAndMax(int first, int second)
{
	Fixed	a(first);
	Fixed	b(second);

	std::cout << "\nMin and max\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << "min: " << Fixed::min(a, b) << "\n";
	std::cout << "max: " << Fixed::max(a, b) << "\n";
}

void	arithmeticOperators(float first, float second)
{
	Fixed	a(first);
	Fixed	b(second);

	std::cout << "\nArithmetic operators\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << a << " + " << b << ": " << a + b << "\n";
	std::cout << a << " - " << b << ": " << a - b << "\n";
	std::cout << a << " * " << b << ": " << a * b << "\n";
	std::cout << a << " / " << b << ": " << a / b << "\n";
	std::cout << a << " + " << b << " + " << b << " + " << a << ": " << a + b + b + a << "\n";
	std::cout << a << " + " << b << " - " << b << ": " << a + b - b << "\n";
}

void	arithmeticOperators(int first, int second)
{
	Fixed	a(first);
	Fixed	b(second);

	std::cout << "\nArithmetic operators\nWith numbers "<< first << " and " << second << "\n";
	std::cout << "Numbers as fixed points "<< a << " and " << b << "\n";
	std::cout << a << " + " << b << ": " << a + b << "\n";
	std::cout << a << " - " << b << ": " << a - b << "\n";
	std::cout << a << " * " << b << ": " << a * b << "\n";
	std::cout << a << " / " << b << ": " << a / b << "\n";
	std::cout << a << " + " << b << " + " << b << " + " << a << ": " << a + b + b + a << "\n";
	std::cout << a << " + " << b << " - " << b << ": " << a + b - b << "\n";
}

int main(void) {
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
	minAndMax(12.1f, 12.2f);
	minAndMax(1, 4);
	minAndMax(1, 1);
	minAndMaxConst(1, 1);
	minAndMaxConst(12.424f, 12.423f);
	arithmeticOperators(1.1f, 1.2f);
	arithmeticOperators(102, 2);
	arithmeticOperators(9, 3);
	arithmeticOperators(9.0f, 3.0f);

	std::cout << "\nSome extra increment and decrement stuff\n";
	{
		Fixed a;

		std::cout << "a at start: " << a << "\n";
		std::cout << "Increment a then check for equality\n";
		std::cout << (++a == a);
		std::cout << "\nPostfix increment a then check for equality\n";
		std::cout << (a++ == a) << "\n";
	}

	return 0;
}

