/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/30 10:47:40 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/08/30 10:47:40 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include "defines.h"
#include <vector>
#include <list>
#include <algorithm>

void	fillVector(char *argv[], std::vector<int>& veccie)
{
	for (size_t i = 0; i < veccie.size(); ++i) {
		std::string	stringNumber(argv[i + 1]);
		if (stringNumber.empty() || stringNumber.find_first_not_of("0123456789") != std::string::npos) {
			throw std::invalid_argument("Empty string or invalid characters in argument: " + stringNumber);
		}
		veccie[i] = stoi(stringNumber);
	}
}

void	checkDuplicates(std::vector<int> veccie) {
	std::sort(veccie.begin(), veccie.end());
	if (std::adjacent_find(veccie.begin(), veccie.end()) != veccie.end()) {
		throw std::invalid_argument("Duplicate numbers in input");
	}
}

template <typename T>
void	printForOutput(std::string const& text, T const& container) {
	std::cout << text;
	size_t i = 0;
	for (int number : container) {
		if (i == 10) {
			std::cout << "[...]";
			break ;
		}
		std::cout << number << " ";
		++i;
	}
	std::cout << "\n";
}

template <typename T>
void	sortAndPrint(std::string const& containerType, T& container, bool printSorted) {
	auto	begin = std::chrono::high_resolution_clock::now();
	PmergeMe<T>::sortContainer(container);
	auto	end = std::chrono::high_resolution_clock::now();
	if (printSorted) {
		printForOutput("After: ", container);
	}
	std::cout << "Is it sorted: " << std::boolalpha << std::is_sorted(container.begin(), container.end());
	std::cout << ". Time to process a range of " << container.size() << " elements with std::" << containerType << ": " <<  std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "us\n";
}

int	main(int argc, char *argv[])
{
	std::vector<int>	veccie(argc - 1);

	try {
		fillVector(argv, veccie);
		checkDuplicates(veccie);
		std::list<int>	listie(veccie.begin(), veccie.end());

		printForOutput("Before: ", veccie);
		sortAndPrint("vector", veccie, true);
		sortAndPrint("list", listie, false);
	}
	catch (std::out_of_range &e) {
		std::cout << REDSTRING("One of the numbers is outside of integer range\n");
		return (1);
	}
	catch (std::invalid_argument &e) {
		std::cout << REDSTRING(e.what()) << "\n";
		return (1);
	}
}
