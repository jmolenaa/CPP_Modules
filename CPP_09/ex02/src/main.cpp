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
#include <algorithm>

void	fillVector(char *argv[], std::vector<int>& veccie)
{
	for (size_t i = 0; i < veccie.size(); ++i) {
		std::string	stringNumber(argv[i + 1]);
		if (stringNumber.empty() || stringNumber.find_first_not_of("0123456789") != std::string::npos) {
			throw std::invalid_argument("Empty string or invalid characters in argument: " + stringNumber);
		}
		veccie[i] = stoi(stringNumber);
//		std::cout << "size and stray" << std::endl;
	}
}

void	checkDuplicates(std::vector<int> const& veccie) {
	if (std::any_of(veccie.begin(), veccie.end(), [veccie](int i){return (std::count(veccie.begin(), veccie.end(), i) != 1);})) {
		throw std::invalid_argument("Duplicate numbers in input");
	}
}

#include <forward_list>

int	main(int argc, char *argv[])
{
	std::vector<int>	veccie(argc - 1);

//	std::forward_list<int>	listie{1, 2, 10, 12};
//
//	auto it	= listie.begin();
//	auto ite = listie.end();
//	while (it < ite) {
//
//		++it;
//	}

	try {
		std::cout << "size and stray" << std::endl;
		fillVector(argv, veccie);
		std::cout << "huh" << std::endl;
		checkDuplicates(veccie);

		PmergeMe	sorter;
		sorter.sortContainer(veccie);
	}
	catch (std::out_of_range &e) {
		std::cout << REDSTRING("One of the numbers is outside of integer range\n");
		return (1);
	}
	catch (std::invalid_argument &e) {
		std::cout << REDSTRING(e.what()) << "\n";
		return (1);
	}
//	std::cout << veccie.size() << "\n";
}
