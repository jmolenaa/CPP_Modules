/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/30 10:47:44 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/08/30 10:47:44 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 30-8-24.
//

#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <vector>
#include <cstddef>
#include <list>

typedef std::vector<int>	intVec;
typedef std::list<int>		intList;

template <typename T>
class PmergeMe {

public:
	PmergeMe() = default;
	PmergeMe(PmergeMe const& src) = default;
	PmergeMe&	operator=(PmergeMe const& rhs) = default;
	~PmergeMe() = default;

	static void	sortContainer(T &container);

private:
	static void		_sortIndividualPairs(T &container, size_t containerSize);
	static size_t	_setSize(T &container);
	static void		_mergeSortPairs(T &container, size_t left, size_t right);
	static void		_mergePairs(T &container, size_t left, size_t mid, size_t right);
	static void		_insertAndEraseElement(T& container, typename T::iterator& insertPos, typename T::iterator& erasePos);
	static void		_movePair(T& container, typename T::iterator& insertPos, typename T::iterator& erasePos);
	static void		_prepMainAndPendChain(T &container, size_t containerSize);
	static void		_insertSecondPairElement(T& container, size_t containerSize);
	static size_t	_jacobsthal(int n);
	static void		_binaryInsert(T& container, typename T::iterator nbr, size_t start, size_t end);


	size_t				_containerSize;

};

#include "PmergeMe.tpp"

#endif //CPP09_PMERGEME_HPP
