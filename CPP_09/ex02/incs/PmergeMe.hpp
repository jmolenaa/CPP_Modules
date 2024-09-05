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

class PmergeMe {

public:
	PmergeMe() = default;
	PmergeMe(PmergeMe const& src) = default;
	PmergeMe&	operator=(PmergeMe const& rhs) = default;
	~PmergeMe() = default;

	void	sortContainer(std::vector<int> &container);

private:


};


#endif //CPP09_PMERGEME_HPP
