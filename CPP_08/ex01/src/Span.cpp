/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/16 12:12:38 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/16 12:12:38 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 16-7-24.
//

#include "Span.hpp"
#include "defines.h"
#include <algorithm>
#include <utility>

typedef std::vector<int>::const_iterator vectorIt;

Span::Span() : _maximumSize(0) {
}

Span::Span(unsigned int N) : _maximumSize(N) {
}

Span::Span(const Span &src) : _maximumSize(src._maximumSize) {
}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_maximumSize = rhs._maximumSize;
		this->_numbers = rhs._numbers;
	}
	return *this;
}

void Span::addNumber(int number) {
	if (this->_numbers.size() == this->_maximumSize) {
		throw Span::SpanIsFullException();
	}
	this->_numbers.emplace_back(number);
}

void Span::_generateNumbers(std::function<int()> genFunc) {
	if (this->_numbers.size() == this->_maximumSize) {
		return ;
	}
	size_t previousSize = this->_numbers.size();
	this->_numbers.resize(this->_maximumSize);
	std::generate(std::next(this->_numbers.begin(), previousSize), this->_numbers.end(), std::move(genFunc));
}

void Span::fillSpan() {
	srand(time(nullptr));
	_generateNumbers([]() -> int {return rand() % 2000;});
}

void Span::fillSpan(std::function<int()> genFunc) {
	if (genFunc == nullptr) {
		srand(time(nullptr));
		genFunc = []() -> int {return rand() % 2000;};
	}
	_generateNumbers(genFunc);
}


size_t Span::longestSpan() const {
	if (this->_numbers.size() < 2) {
		throw Span::SpanTooSmallException("longest");
	}
	std::pair<vectorIt , vectorIt> minMaxPair = std::minmax_element(this->_numbers.begin(), this->_numbers.end());
	return (*minMaxPair.second - *minMaxPair.first);
}

size_t Span::shortestSpan() const {
	if (this->_numbers.size() < 2) {
		throw Span::SpanTooSmallException("shortest");
	}
	std::vector<int>	tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());
	std::transform(std::next(tmp.begin()), tmp.end(), tmp.begin(), tmp.begin(), std::minus<int>());
	tmp.pop_back();
	return *(std::min_element(tmp.begin(), tmp.end()));
}

const char *Span::SpanIsFullException::what() const noexcept {
	return ("Span does not have space for the number of elements being added\n");
}

const char *Span::SpanTooSmallException::what() const noexcept {
	return (this->_functionCalled.c_str());
}

Span::SpanTooSmallException::SpanTooSmallException(const std::string &functionCalled) {
	this->_functionCalled = "Span has less than two elements, so can't find " + functionCalled + " span\n";
}

void Span::printSpan() const {
	std::cout << BLUE << "Printing span\n" << RESET;
	std::for_each(this->_numbers.begin(), this->_numbers.end(), [](int nb){std::cout << nb << "\n";});
	std::cout << "\n";
}
