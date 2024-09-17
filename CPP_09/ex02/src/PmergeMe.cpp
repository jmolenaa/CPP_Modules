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

void PmergeMe::_setSize(std::vector<int> &container) {
	this->_containerSize = 0;
	for (auto it = container.begin(); it < container.end(); ++it) {
		this->_containerSize++;
	}
}

void PmergeMe::_sortIndividualPairs(std::vector<int> &container) const{
	for (size_t i = 1; i < this->_containerSize; i+=2) {
		if (container[i] > container[i - 1]) {
			std::swap(container[i], container[i - 1]);
		}
	}
}

void PmergeMe::_insertAndEraseElement(std::vector<int> &container, std::vector<int>::iterator insertPos,
									  std::vector<int>::iterator erasePos) {
	int value = *erasePos;
	container.erase(erasePos);
	container.insert(insertPos, value);
}

void PmergeMe::_mergePairs(std::vector<int> &container, size_t left, size_t mid, size_t right) {

//	// iterator for writing into the main container, starts at the very beginning of the first half
	auto	itSubArray1 = std::next(container.begin(), left);
	// second half gets the iterator in the middle of the part being merged and on the right side
	auto	itSubArray2 = std::next(container.begin(), mid + 1);
	size_t	counterSubArray1 = left;
	size_t	endSubArray1 = mid;
	size_t	counterSubArray2 = mid + 1;
	size_t	endSubArray2 = right;

	while (counterSubArray1 <= endSubArray1 && counterSubArray2 <= endSubArray2) {
		// If the element at itSubArray1 is smaller or equal, no change is needed
		if (*itSubArray1 <= *itSubArray2) {
			itSubArray1+=2;
			counterSubArray1+=2;
		}
		else {
			if (counterSubArray2 != endSubArray2) {
				_insertAndEraseElement(container, itSubArray1, itSubArray2 + 1);
				_insertAndEraseElement(container, itSubArray1, itSubArray2 + 1);
			}

			// Update pointers
			itSubArray1+=2;
			endSubArray1+=2;
			itSubArray2+=2;
			counterSubArray2+=2;
			counterSubArray1+=2;
		}
	}
}

void PmergeMe::_mergeSortPairs(std::vector<int> &container, size_t left, size_t right) {
	if (right - left <= 1) {
		return ;
	}

	size_t mid = left + (right - left) / 2;
	if ((mid - left + 1) % 2 != 0) {
		++mid;
	}
	_mergeSortPairs(container, left, mid);
	_mergeSortPairs(container, mid + 1, right);
	_mergePairs(container, left, mid, right);
}

void	printContainer(std::vector<int> const&container) {
	for (int number : container) {
		std::cout << number << " ";
	}
	std::cout << "\n";
}

void PmergeMe::_prepMainAndPendChain(std::vector<int> &container) const {
	auto	itMainChain = container.begin() + 1;
	auto	it = container.begin() + 2;
	for (size_t i = 2; i < this->_containerSize - 1; i+=2) {
		_insertAndEraseElement(container, itMainChain, it);
		++itMainChain;
		it+=2;
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

void PmergeMe::_binaryInsert(std::vector<int> &container, std::vector<int>::iterator itNbr, size_t start, size_t end) const {
	if (start >= end) {
		_insertAndEraseElement(container, container.begin() + start, itNbr);
//		container.insert(container.begin() + start, *itNbr);
		//insert function
		return;
	}

	size_t mid = start + (end - start) / 2;

	if (*(std::next(container.begin(), mid)) == *itNbr) {
		_insertAndEraseElement(container, container.begin() + mid, itNbr);
//		container.insert(container.begin() + mid, *itNbr);
		//insert function
	}
	else if (*(std::next(container.begin(), mid)) > *itNbr) {
		_binaryInsert(container, itNbr, start, mid);
	}
	else {
		_binaryInsert(container, itNbr, mid + 1, end);
	}

}

void PmergeMe::_insertSecondPairElement(std::vector<int> &container) const{

	int		currentJacob = 3;
	size_t	i = 1;
	size_t	pendChainSize = this->_containerSize / 2 + this->_containerSize % 2;
	size_t	mainChainSize = this->_containerSize / 2;
	_insertAndEraseElement(container, container.begin(), std::next(container.begin(), this->_containerSize / 2));
	while (i < pendChainSize) {
		size_t	endJacob = _jacobsthal(currentJacob - 1);
		for (size_t j = _jacobsthal(currentJacob); j > endJacob; ++endJacob) {
			auto	pendIterator = std::next(container.begin(), this->_containerSize / 2);
			if (j >= pendChainSize) {
				j = pendChainSize;
			}
			std::advance(pendIterator, j - 1);
			this->_binaryInsert(container, pendIterator, 0, mainChainSize + i);
			++i;
		}
		++currentJacob;
	}
}

void PmergeMe::sortContainer(std::vector<int> &container) {
	std::cout << "size and stray" << std::endl;
	this->_setSize(container);
	printContainer(container);
	std::cout << "sort individuals" << std::endl;
	this->_sortIndividualPairs(container);
	printContainer(container);
	std::cout << "merge sort" << std::endl;
	_mergeSortPairs(container, 0, this->_containerSize - 1);
	printContainer(container);
//	std::vector<int>	lol;
//	size_t j = 0;
//	for (int i : container) {
//		if (j % 2 == 0 && j != this->_containerSize - 1) {
//			lol.push_back(i);
//		}
//		++j;
//	}
//	printContainer(lol);
//	std::cout << "Is it sorted: " << std::is_sorted(lol.begin(), lol.end()) << "\n";
	std::cout << "prep chain" << std::endl;
	this->_prepMainAndPendChain(container);
	printContainer(container);

	std::cout << "insert" << std::endl;
	this->_insertSecondPairElement(container);
	printContainer(container);
	std::cout << "Is it sorted: " << std::is_sorted(container.begin(), container.end()) << "\n";
}
