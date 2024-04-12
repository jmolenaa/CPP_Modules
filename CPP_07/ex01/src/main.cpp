/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 14:00:53 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/12 14:00:53 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Fixed.hpp"
#include <iostream>
#include "defines.h"

template <typename T>
void	print(T i) {
	std::cout << i << " ";
}

template <typename T>
void	addOne(T variable) {
	++variable;
}

int	main() {
	int	arr[10];
	for (size_t i = 0; i < 10; ++i) {
		arr[i] = rand() % 20;
	}
	std::cout << BLUE << "Array of integers\n";
	std::cout << "Array before increment\n" << RESET;
	iter(arr, 10, print);
	std::cout << "\n";
	iter(arr, 10, addOne);
	std::cout << BLUE << "Array after increment\n" << RESET;
	iter(arr, 10, print);
	std::cout << "\n";

	char arr2[10];
	for (size_t i = 0; i < 10; ++i) {
		arr2[i] = rand() % (127 - 35) + 33;
	}
	std::cout << BLUE << "\nArray of chars\n";
	std::cout << "Array before increment\n" << RESET;
	iter(arr2, 10, print);
	std::cout << "\n";
	iter(arr2, 10, addOne);
	std::cout << BLUE << "Array after increment\n" << RESET;
	iter(arr2, 10, print);
	std::cout << "\n";

	Fixed	arr3[10] = {10, 12.4f, 1, 22.3f, 33, 4, 5, 7777.4f, 123213, 1.444f};
	std::cout << BLUE << "\nArray of fixed classes\n";
	std::cout << "Array before increment\n" << RESET;
	iter(arr3, 10, print);
	std::cout << "\n";
	iter(arr3, 10, addOne);
	std::cout << BLUE << "Array after increment\n" << RESET;
	iter(arr3, 10, print);
	std::cout << "\n";
}
