/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/18 18:37:27 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/18 18:37:27 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include "defines.h"
#include <algorithm>

template <typename iterator>
void	printStack(iterator begin, iterator end) {
	std::cout << GREENSTRING("Current stack: ");
	for (; begin != end; ++begin) {
		std::cout << *begin << " ";
	}
	std::cout << "\n";
}

int	main() {
	{
		std::cout << INFOSTRING("Subject tests\n");
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << INFOSTRING("\nSubject tests but with list\n");
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{

		MutantStack<int>	mstack;
		mstack.push(20);
		mstack.push(10);
		mstack.push(5);
		mstack.push(1);
		mstack.push(0);

		std::cout << INFOSTRING("\nJust tests showing you can use other types of iterators\nNormal Iterators\n");
		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();
		printStack(it, ite);


		std::cout << INFOSTRING("\nUsing iterator to change first value to 25 and then changing all values by 1 and printing again\n");
		*it = 25;
		std::transform(it, ite, it, [](int x){return x + 1;});
		printStack(it, ite);


		std::cout << INFOSTRING("\nSorting stack\n");
		std::sort(it, ite);
		printStack(it, ite);


		std::cout << INFOSTRING("\nConstant iterators, should have a look at the commented code to see that they are indeed constant\n");
		MutantStack<int>::const_iterator	cit = mstack.cbegin();
		MutantStack<int>::const_iterator	cite = mstack.cend();
		printStack(cit, cite);
//		*cit = 10;
//		std::sort(cit, cite);


		std::cout << INFOSTRING("\nReverse iterators\n");
		MutantStack<int>::reverse_iterator	rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator	rite = mstack.rend();
		printStack(rit, rite);


		std::cout << INFOSTRING("\nUsing iterator to change first value to 30 and then changing all values by 1 and printing again\n");
		*rit = 30;
		std::transform(rit, rite, rit, [](int x){return x + 1;});
		printStack(rit, rite);

		std::cout << INFOSTRING("\nReverse const iterators, should have a look at the commented code to see that they are indeed constant\n");
		MutantStack<int>::const_reverse_iterator 	crit = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator 	crite = mstack.rend();
		printStack(crit, crite);
//		*crit = 10;
//		std::sort(crit, crite);
	}
	{
		std::cout << INFOSTRING("\nGiving a different underlying container to the mutant stack\n");
		MutantStack<int, std::vector<int>>	mstack;
		mstack.push(10);
		mstack.push(1);
		mstack.push(0);
		mstack.push(-10);
		mstack.push(12310);
		printStack(mstack.begin(), mstack.end());
	}
	return 0;
}