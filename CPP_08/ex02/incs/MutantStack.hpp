/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/18 18:37:11 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/18 18:37:11 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {

public:
	MutantStack() = default;
	MutantStack(MutantStack const& src) {
		this->c = src.c;
	};
	MutantStack&	operator=(MutantStack const&rhs) {
		if (this != &rhs) {
			this->c = rhs.c;
		}
		return *this;
	};
	~MutantStack() = default;

	typedef typename Container::iterator				iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator					begin()				{return (this->c.begin());};
	iterator					end() 				{return (this->c.end());};
	reverse_iterator 			rbegin()			{return (this->c.rbegin());};
	reverse_iterator 			rend()				{return (this->c.rend());};
	const_iterator 				cbegin() const		{return (this->c.cbegin());};
	const_iterator 				cend() const		{return (this->c.cend());};
	const_reverse_iterator 		crbegin() const		{return (this->c.crbegin());};
	const_reverse_iterator 		crend() const		{return (this->c.crend());};

private:

};

#endif