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
#include <list>
#include <chrono>

template <typename T>
void	printContainer(T const&container) {
	for (int number : container) {
		std::cout << number << " ";
	}
	std::cout << "\n";
}

template <typename T>
size_t PmergeMe<T>::_setSize(T &container) {
	size_t containerSize = 0;
	for (auto it = container.begin(); it != container.end(); ++it) {
		++containerSize;
	}
	return containerSize;
}

template <typename T>
void PmergeMe<T>::_sortIndividualPairs(T &container, size_t containerSize) {
	auto	it = container.begin();
	// we start at 1, so we stop whenever we reach either the end of the container in and even case, or the stray number in uneven
	for (size_t i = 1; i < containerSize; i+=2) {
		if (*it < *std::next(it)) {
			std::swap(*it, *std::next(it));
		}
		it = std::next(it, 2);
	}
}

// for vector it's straightforward, we don't need ot adjust iterators
// the iterators will still point to the same spots because the vector won't change in size
template <>
void PmergeMe<intVec>::_insertAndEraseElement(intVec &container, intVec::iterator& insertPos,
											  intVec::iterator& erasePos) {
	if (insertPos == erasePos) {
		return;
	}
	int value = *erasePos;
	container.erase(erasePos);
	container.insert(insertPos, value);
}

// we grab the next iterator, cause we want to move from the back to the front
// as in 1 2 .. 6 8, if we move pair 6 and 8, we start with moving the 8, then the 6
// the six will have moved to the spot of 8 due to the insertion
template <>
void PmergeMe<intVec>::_movePair(intVec &container, intVec::iterator& insertPos, intVec::iterator& erasePos) {
	auto eraseIt = erasePos + 1;
	_insertAndEraseElement(container, insertPos, eraseIt);
	_insertAndEraseElement(container, insertPos, eraseIt);
}

// for a list we need to actually save our previous node, because after erasing the current one is invalid
// we are using the itSubArray1 and 2 from the main merging function,
// so we need to make those valid and point to the same spot, order wise
// so if 1 2 4 5 8 6, we move 8 and 6 to the beginning, so 8 6 1 2 4 5
// our insertPos needs to point to 8 and erasePos to 4
// insert function inserts before the node, so we need to adjust it to point to the newly inserted node
template <>
void PmergeMe<intList>::_insertAndEraseElement(intList &container, intList::iterator& insertPos,
											   intList::iterator& erasePos) {
	if (insertPos == erasePos) {
		return ;
	}
	int value = *erasePos;
	auto temp = std::prev(erasePos);
	container.erase(erasePos);
	erasePos = temp;
	container.insert(insertPos,value);
	insertPos = std::prev(insertPos);
}

// the incrementing and decrementing is, so we end up with the correct position
// this is the order, at the start erasePos is 8 and insertPos is 1
// 1 2 | 5 3 | 8 6, we move 6 to the front, erasePos is 6 and insertPos is 1
// 6 1 2 5 3 8, erasePos is 8 and insertPos is 6, we move 8
// 8 6 1 2 5 3, our insertPos is 8 and erasPos is 3, we want erasPos in the same numerical spot as before, so we decrement to 5
template <>
void PmergeMe<intList>::_movePair(intList &container, intList::iterator& insertPos, intList::iterator& erasePos) {
	erasePos++;
	_insertAndEraseElement(container, insertPos, erasePos);
	_insertAndEraseElement(container, insertPos, erasePos);
	erasePos--;
}

template <typename T>
void PmergeMe<T>::_mergePairs(T &container, size_t left, size_t mid, size_t right) {

	// iterator for writing into the main container, starts at the very beginning of the first half
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
			itSubArray1 = std::next(itSubArray1, 2);
			counterSubArray1+=2;
		}
		else {
			// this is so we don't sort the stray number, or any uneven number
			// merge sort splits into subarrays, I make sure the left one is always even, but the right one might be uneven
			// in that case we just leave the last number be
			if (counterSubArray2 != endSubArray2) {
				_movePair(container, itSubArray1, itSubArray2);
			}

			// Update pointers
			itSubArray1 = std::next(itSubArray1, 2);
			itSubArray2 = std::next(itSubArray2, 2);
			counterSubArray2+=2;
		}
	}
}


template <typename T>
void PmergeMe<T>::_mergeSortPairs(T &container, size_t left, size_t right) {
	if (right - left <= 1) {
		return ;
	}

	size_t mid = left + (right - left) / 2;
	// making sure the left is even
	if ((mid - left + 1) % 2 != 0) {
		++mid;
	}
	_mergeSortPairs(container, left, mid);
	_mergeSortPairs(container, mid + 1, right);
	_mergePairs(container, left, mid, right);
}

// inserting the first parts of the pairs into the beginning of the container
template <typename T>
void PmergeMe<T>::_prepMainAndPendChain(T &container, size_t containerSize) {
	auto	itMainChain = std::next(container.begin(), 1);
	auto	it = std::next(container.begin(), 2);
	for (size_t i = 2; i < containerSize - 1; i+=2) {
		_insertAndEraseElement(container, itMainChain, it);
		++itMainChain;
		it = std::next(it, 2);
	}
}

template <typename T>
size_t PmergeMe<T>::_jacobsthal(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return (_jacobsthal(n - 1) + 2 * _jacobsthal(n - 2));
}

template <typename T>
void PmergeMe<T>::_binaryInsert(T &container, typename T::iterator itNbr, size_t start, size_t end) {
	if (start >= end) {
		auto	insertIt = std::next(container.begin(), start);
		_insertAndEraseElement(container, insertIt, itNbr);
		return;
	}

	size_t mid = start + (end - start) / 2;

	if (*(std::next(container.begin(), mid)) == *itNbr) {
		auto	insertIt = std::next(container.begin(), mid);
		_insertAndEraseElement(container, insertIt, itNbr);
	}
	else if (*(std::next(container.begin(), mid)) > *itNbr) {
		_binaryInsert(container, itNbr, start, mid);
	}
	else {
		_binaryInsert(container, itNbr, mid + 1, end);
	}

}

template <typename T>
void PmergeMe<T>::_insertSecondPairElement(T &container, size_t containerSize) {

	// we start from 3 cause the jacobsthal number are {1,1,3,5..}
	// we already do index 1 at the start so might as well jump to the third number immediately
	int		currentJacob = 3;
	size_t	i = 1;
	size_t	pendChainSize = containerSize / 2 + containerSize % 2;
	size_t	mainChainSize = containerSize / 2;

	// adds the first element form the pend chain into the beginning of the container
	// this is cause the first pair was sorted ascendingly and the pairs are sorted increasignly
	// so the second number of the first pair is always smaller than all the other ones
	auto	eraseIt = std::next(container.begin(), containerSize / 2);
	auto	insertIt = container.begin();
	_insertAndEraseElement(container, insertIt, eraseIt);

	while (i < pendChainSize) {
		size_t	endJacob = _jacobsthal(currentJacob - 1);
		for (size_t j = _jacobsthal(currentJacob); j > endJacob; ++endJacob) {
			auto	pendIterator = std::next(container.begin(), containerSize / 2);
			if (j >= pendChainSize) {
				j = pendChainSize;
			}
			std::advance(pendIterator, j - 1);
			_binaryInsert(container, pendIterator, 0, mainChainSize + i);
			++i;
		}
		++currentJacob;
	}
}

template <typename T>
void PmergeMe<T>::sortContainer(T &container) {
	size_t	containerSize = _setSize(container);
	_sortIndividualPairs(container, containerSize);
	_mergeSortPairs(container, 0, containerSize - 1);
	_prepMainAndPendChain(container, containerSize);
	_insertSecondPairElement(container, containerSize);
}
