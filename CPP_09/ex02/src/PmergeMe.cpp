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
#include <algorithm>

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

void PmergeMe::_setSizeAndStray(std::vector<int> &container) {
	this->_containerSize = 0;
	for (auto it = container.begin(); it < container.end(); ++it) {
		this->_containerSize++;
		this->_stray = *it;
	}
	if (this->_containerSize % 2 == 0) {
		this->_stray = -1;
	}
}

void PmergeMe::_mergePairs(std::vector<int> &container, size_t left, size_t mid, size_t right) const {

//	std::cout << "\n";
//	std::cout << "left: " << left << " right: " << right << " mid: " << mid << "\n";
//	std::cout << "container: ";
//	for (size_t i = left; i < right; ++i) {
//		std::cout << container[i] << " ";
//	}
//	std::cout << "|\n";
	// sets up first temporary subarray for the first half
	// this is so because merging from the second half into the main container
	// will overwrite values form the first half
	// we don't need a temporary second half because we won't be overwriting it
//	std::vector<int>	subArray1(std::next(container.begin(), left), std::next(container.begin(), mid + 1));
////	for (int i : subArray1) {
////		std::cout << i << " ";
////	}
////	std::cout << "|\n";
//
//	// sets iterators for both halfs, first half is self-explanatory
//	auto	itSubArray1 = subArray1.begin();
//	auto	iteSubArray1 = subArray1.end();
//	// second half gets the iterator in the middle of the part being merged and at the right side
//	auto	itSubArray2 = std::next(container.begin(), mid + 1);
//	auto	iteSubArray2 = std::next(container.begin(), right);
//	// iterator for writing into the main container, starts at the very beginning of the first half
//	auto	itContainer = std::next(container.begin(), left);
//
//	// loops until we finish either of the subarrays
//	// writes values to the original container from the first or second subarray depending on which is lower
//	while (itSubArray1 < iteSubArray1 && itSubArray2 <= iteSubArray2) {
//		if (*itSubArray1 <= *itSubArray2) {
//			*itContainer = *itSubArray1;
//			++itSubArray1;
//		}
//		else {
//			*itContainer = *itSubArray2;
//			++itSubArray2;
//		}
//		++itContainer;
//	}
//
//	// if there is still values in the first subarray we copy them over to the original container
//	// (means we exited the loop because we got all the values from the second one)
//	// we don't need to do the same if there is values in the second half, since those are in the original container anyway
//	while (itSubArray1 < iteSubArray1) {
//		*itContainer = *itSubArray1;
//		++itContainer;
//		++itSubArray1;
//	}


//	auto	itSubArray1 = 0;
//	auto	itSubArray2 = mid + 1;
//	auto	sizeSubArray1 = mid - left + 1;
//	auto	sizeSubArray2 = right - mid;
//	auto	itContainer = left;
//	sizeSubArray2+=itSubArray2;
//
//	std::cout << "iterators: " << itSubArray1 << " " << itSubArray2 << " " << itContainer << "\n";
//	while (itSubArray1 < sizeSubArray1 && itSubArray2 < sizeSubArray2) {
//		if (subArray1[itSubArray1] <= container[itSubArray2]) {
//			container[itContainer] = subArray1[itSubArray1];
//			++itSubArray1;
//		}
//		else {
//			container[itContainer] = container[itSubArray2];
//			++itSubArray2;
//		}
//		++itContainer;
//	}
//
//	while (itSubArray1 < sizeSubArray1) {
//		container[itContainer] = subArray1[itSubArray1];
//		++itContainer;
//		++itSubArray1;
//	}

//	size_t	itSubArray1 = 0;
//	auto	itSubArray2 = mid + 1;
//	auto	sizeSubArray1 = mid - left + 1;
//	auto	sizeSubArray2 = right - mid;
//	auto	itContainer = left;
	auto	itSubArray1 = std::next(container.begin(), left);
	auto	iteSubArray1 = std::next(container.begin(), mid);
	// second half gets the iterator in the middle of the part being merged and at the right side
	auto	itSubArray2 = std::next(container.begin(), mid + 1);
	auto	iteSubArray2 = std::next(container.begin(), right);
	// iterator for writing into the main container, starts at the very beginning of the first half
//	auto	itContainer = std::next(container.begin(), left);
//	sizeSubArray2+=itSubArray2;

	while (itSubArray1 <= iteSubArray1 && itSubArray2 <= iteSubArray2) {
		// If the element at itSubArray1 is smaller or equal, no change is needed
		if (*itSubArray1 <= *itSubArray2) {
			itSubArray1+=2;
		} else {
			// If the element at itSubArray2 is smaller, we need to move it to the correct position
			auto index = itSubArray1;
			int value = *index;
			int	value2 = *(index + 1);

			// Shift all the elements between itSubArray1 and itSubArray2 to the right by one
			while (index < itSubArray2) {
				int	temp = *(index + 2);
				int	temp2 = *(index + 3);
				*(index + 2) = value;
				*(index + 3) = value2;
//				*index = *(index - 1);
				index+=2;
				value = temp;
				value2 = temp2;
			}

			*itSubArray1 = value;
			if (itSubArray1 + 1 != iteSubArray2) {
				*(itSubArray1 + 1) = value2;
			}

			// Update pointers
			itSubArray1+=2;
			iteSubArray1+=2;
			itSubArray2+=2;
		}
	}
}

void PmergeMe::_mergeSortPairs(std::vector<int> &container, size_t left, size_t right) const {
	if (right - left <= 1) {
		return ;
	}

	size_t mid = left + (right - left) / 2;
	if ((mid - left + 1) % 2 != 0) {
		++mid;
	}
	this->_mergeSortPairs(container, left, mid);
	this->_mergeSortPairs(container, mid + 1, right);
	this->_mergePairs(container, left, mid, right);
}

void PmergeMe::_sortIndividualPairs(std::vector<int> &container) const{
	for (size_t i = 1; i < this->_containerSize; i+=2) {
		if (container[i] < container[i - 1]) {
			std::swap(container[i], container[i - 1]);
		}
	}
}

static void	printContainer(std::vector<int> const&container) {
	size_t j = 0;
	for (int number : container) {
		std::cout << number << " ";
//		if (j % 2 == 1) {
//			std::cout << "| ";
//		}
		j++;
	}
	std::cout << "\n";
}

void PmergeMe::_fillMainAndPendChain(const std::vector<int> &container, std::vector<int> &mainChain, std::vector<int> &pendChain) const {
	size_t j = 0;
	auto itMainChain = mainChain.begin();
	auto itPendChain = pendChain.begin();
	for (int nbr : container) {
		if (j % 2 == 0 && j != this->_containerSize - 1) {
			*itMainChain = nbr;
			++itMainChain;
		}
		else {
			*itPendChain = nbr;
			++itPendChain;
		}
		++j;
	}
}

size_t PmergeMe::_jacobsthal(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return (_jacobsthal(n - 1) + 2 * _jacobsthal(n - 2));
}


void PmergeMe::_binaryInsert(std::vector<int> &container, int nbr, size_t start, size_t end) const {
	if (start >= end) {
		container.insert(container.begin() + start, nbr);
		//insert function
		return;
	}

	size_t mid = start + (end - start) / 2;

	if (*(std::next(container.begin(), mid)) == nbr) {
		container.insert(container.begin() + mid, nbr);
		//insert function
	}
	else if (*(std::next(container.begin(), mid)) > nbr) {
		_binaryInsert(container, nbr, start, mid);
	}
	else {
		_binaryInsert(container, nbr, mid + 1, end);
	}

}

void PmergeMe::_insertSecondPairElement(std::vector<int> &container) const{

	int		currentJacob = 1;
	size_t	i = 1;
//	auto	itContainer = container.begin();
	size_t	pendChainSize = this->_containerSize / 2 + this->_containerSize % 2;
	size_t	mainChainSize = this->_containerSize / 2;
	std::vector<int>	mainChain(mainChainSize);
	std::vector<int>	pendChain(pendChainSize);

	this->_fillMainAndPendChain(container, mainChain, pendChain);
	printContainer(mainChain);
	printContainer(pendChain);

	mainChain.insert(mainChain.begin() + 1, *pendChain.begin());
	while (i < pendChainSize) {

		size_t	endJacob = _jacobsthal(currentJacob - 1);
		for (size_t j = _jacobsthal(currentJacob); j > endJacob; --j) {
			auto	pendIterator = pendChain.begin();
			if (j >= pendChainSize) {
				j = pendChainSize - 1;
			}
			std::advance(pendIterator, j);
			this->_binaryInsert(mainChain, *pendIterator, 0, mainChainSize + i);
			++i;
//			std::cout << "huh" << std::endl;
//			std::cout << j << "\n";
//			std::cout << this->_containerSize << "\n";
		}
//		std::cout << "haaah" << std::endl;
//		std::cout << pendChainSize << "\n";
		++currentJacob;
	}
	container = mainChain;
}

void PmergeMe::sortContainer(std::vector<int> &container) {
	this->_setSizeAndStray(container);
	printContainer(container);
	this->_sortIndividualPairs(container);
	printContainer(container);
//	printContainer(mainChain);
//	printContainer(pendChain);

	this->_mergeSortPairs(container, 0, this->_containerSize - 1);
	printContainer(container);
//	std::vector<int>	lol;
//	int j = 0;
//	for (int i : container) {
//		if (j % 2 == 0) {
//			lol.push_back(i);
//		}
//		++j;
//	}
//	printContainer(lol);
//	std::cout << "Is it sorted: " << std::is_sorted(lol.begin(), lol.end()) << "\n";
	this->_insertSecondPairElement(container);
	printContainer(container);
	std::cout << "Is it sorted: " << std::is_sorted(container.begin(), container.end()) << "\n";
}
