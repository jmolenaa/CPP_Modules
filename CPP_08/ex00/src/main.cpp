/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 13:42:24 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/04 13:42:24 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "defines.h"

template<typename T>
void	fillContainer(T &container) {
	srand(time(NULL));
	for (size_t i = 0; i < 1000; ++i) {
		container.emplace_back(rand());
	}
	for (size_t i = 0; i < 10; ++i) {
		container.emplace_back(i * 10);
	}
}

template<typename T>
void	lookForNumbers(T& container, std::string const& containerType) {
	std::cout << BLUE << "\n\nTesting for container: " << containerType << "\n" << RESET;

	std::cout << GREEN << "Looking for 10, should be in container\n" << RESET;
	typename T::iterator	it = easyFind(container, 10);
	std::cout << "Value at given iterator: " << *it << "\n";
	std::cout << GREEN << "Looking for 100, should not be in container unless rand function generated it\n" << RESET;
	auto	autoIt = easyFind(container, 100);
	std::cout << "Using if statement to show the return is the container.end()\n";
	if (autoIt == container.end()) {
		std::cout << "YEEEEEEES\n";
	}
	else {
		std::cout << "NOOOOOOOO\n";
	}
}

int	main() {
	std::vector<int>	numbers;
	std::list<int>		numbersList;
	std::deque<int>		numbersDeque;
	fillContainer(numbers);
	fillContainer(numbersList);
	fillContainer(numbersDeque);

	lookForNumbers(numbers, "vector");
	lookForNumbers(numbersList, "list");
	lookForNumbers(numbersDeque, "deque");

	std::cout << BLUE << "\n\nShowing for const container it works as well\n" << RESET;
	std::vector<int> const	numbersConst(numbers);


//	std::vector<int>::iterator		 	it = easyFind(numbersConst, 10);
	std::cout << GREEN << "Looking for 10, should be in container\n" << RESET;
	std::vector<int>::const_iterator	constIt = easyFind(numbersConst, 10);
	std::cout << "Value at given iterator: " << *constIt << "\n";

	std::cout << GREEN << "Looking for 100, should not be in container unless rand function generated it\n" << RESET;
	std::cout << "Using if statement to show the return is the container.end()\n";
	auto	autoConstIt = easyFind(numbersConst, 100);
	if (autoConstIt == numbersConst.end()) {
		std::cout << "YEEEEEEES\n";
	}
	else {
		std::cout << "NOOOOOOOO\n";
	}
}
