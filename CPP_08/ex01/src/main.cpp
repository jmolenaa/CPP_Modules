/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/16 12:13:38 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/16 12:13:38 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "defines.h"
#include <iostream>
#include <list>
#include <algorithm>

void	test(unsigned int n) {
	Span sp(n);
	try {
		sp.addNumber(1);
	}
	catch (Span::SpanIsFullException& e) {
		std::cout << RED << e.what() << RESET;
	}
	try {
		sp.shortestSpan();
	}
	catch (Span::SpanTooSmallException& e) {
		std::cout << RED << e.what() << RESET;
	}
	try {
		sp.longestSpan();
	}
	catch (Span::SpanTooSmallException& e) {
		std::cout << RED << e.what() << RESET;
	}
	sp.fillSpan();
	sp.fillSpan(nullptr);
	sp.fillSpan([](){return 1;});
}

int main() {
	{
		std::cout << BLUE << "Subject tests\n" << RESET;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "\n";
		std::cout << BLUE << "Trying to add a number when Span is full\n" << RESET;
		try {
			sp.addNumber(10);
		}
		catch (Span::SpanIsFullException& e) {
			std::cout << RED << e.what() << RESET;
		}
	}
	std::cout << BLUE << "\nSpan of max size 0, we try to add a number, find the longest or shortest span and fill the container\n";
	test(0);
	std::cout << BLUE << "\nSame but for max size 1\n";
	test(1);

	{
		std::cout << BLUE <<"\nTesting for Span with two identical numbers\n" << RESET;
		Span	sp(2);

		sp.addNumber(0);
		sp.addNumber(0);
		std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << BLUE << "\nTesting big spans\nSpan with random numbers\n" << RESET;

		Span	sp(10000);
		sp.fillSpan([](){return rand();});
		std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//		sp.printSpan();
	}
	{
		std::cout << BLUE << "\nSpan with random numbers within 2000\n" << RESET;

		Span	sp(100000);
		sp.fillSpan();
		std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//		sp.printSpan();
	}
	{
		std::cout << BLUE << "\nSpan with ascending numbers\n" << RESET;

		Span	sp(100000);
		sp.fillSpan([](){static int i;++i;return i;});
		std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//		sp.printSpan();
	}
	{
		std::cout << BLUE << "\nSpan with ascending numbers, but adding a -100000 at the start\n" << RESET;

		Span	sp(100000);
		sp.addNumber(-100000);
		sp.fillSpan([](){static int i;++i;return i;});
		std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//		sp.printSpan();
	}
	{
		std::cout << BLUE << "\nSpan with ascending numbers jumping by two\n" << RESET;

		Span	sp(100000);
		sp.fillSpan([](){static int i;i+=2;return i;});
		std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//		sp.printSpan();
	}
	{
		std::cout << BLUE << "\nFilling span with range of iterators from a vector\n" << RESET;

		Span				sp(20);
		std::vector<int>	vec(20);
		std::generate(vec.begin(), vec.end(), [](){static int i;++i;return i;});

		sp.fillSpan(vec.begin(), vec.end());
		sp.printSpan();
	}
	{
		std::cout << BLUE << "\nFilling span with range of iterators from a list\n" << RESET;

		Span				sp(20);
		std::list<int>		lst(20);
		std::generate(lst.begin(), lst.end(), [](){static int i;++i;return i;});

		sp.fillSpan(lst.begin(), lst.end());
		sp.printSpan();
	}
	{
		std::cout << BLUE << "\nTrying to fill span with a list that has more numbers\n" << RESET;

		Span				sp(20);
		std::list<int>		lst(30);
		std::generate(lst.begin(), lst.end(), [](){static int i;++i;return i;});

		try {
			sp.fillSpan(lst.begin(), lst.end());
		}
		catch (Span::SpanIsFullException& e) {
			std::cout << RED << e.what() << RESET;
		}
	}
	return 0;
}

