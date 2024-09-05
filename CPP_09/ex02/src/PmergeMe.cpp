/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/30 10:47:41 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/08/30 10:47:41 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 30-8-24.
//

#include "PmergeMe.hpp"
#include <iostream>

//PmergeMe::PmergeMe() {
//
//}
//
//PmergeMe::PmergeMe(const PmergeMe &src) {
//
//}
//
//PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
//	return *this;
//}
//
//PmergeMe::~PmergeMe() {
//
//}

void PmergeMe::sortContainer(std::vector<int> &container) {

	for (int number : container) {
		std::cout << number << " ";
	}
	std::cout << "\n";


}
