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

class PmergeMe {

public:
	PmergeMe() = default;
	PmergeMe(PmergeMe const& src) = default;
	PmergeMe&	operator=(PmergeMe const& rhs) = default;
	~PmergeMe() = default;

	void	sortContainer(std::vector<int> &container);

private:
	void			_sortIndividualPairs(std::vector<int> &container) const;
	void			_setSizeAndStray(std::vector<int> &container);
	void			_mergeSortPairs(std::vector<int> &container, size_t left, size_t right) const;
	void			_mergePairs(std::vector<int> &container, size_t left, size_t mid, size_t right) const;
	void			_fillMainAndPendChain(std::vector<int> const& container, std::vector<int>& mainChain, std::vector<int>& pendChain) const;
	void			_insertSecondPairElement(std::vector<int>& container) const;
	static size_t	_jacobsthal(int n);
	void			_binaryInsert(std::vector<int>& container, int nbr, size_t start, size_t end) const;


	size_t				_containerSize;
	int					_stray;

};


#endif //CPP09_PMERGEME_HPP
