/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/16 12:12:36 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/16 12:12:36 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 16-7-24.
//

#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include <iostream>
#include <vector>
#include <functional>

class Span {

private:
	size_t 				_maximumSize;
	std::vector<int>	_numbers;
	void				_generateNumbers(std::function<int()> genFunc);

public:
	Span();
	Span(Span const& src);
	Span&	operator=(Span const& rhs);
	explicit Span(unsigned int N);
	~Span() = default;

	void	addNumber(int number);
	size_t	shortestSpan() const;
	size_t	longestSpan() const;

	// fill functions
	void	fillSpan();
	void	fillSpan(std::function<int()> genFunc);
	template<typename T>
	void	fillSpan(T startIt, T endIt) {
		if (std::distance(startIt, endIt) > (ssize_t)(this->_maximumSize - this->_numbers.size())) {
			throw Span::SpanIsFullException();
		}
		this->_numbers.insert(std::next(this->_numbers.begin(), this->_numbers.size()), startIt, endIt);
	}

	void	printSpan() const;

	class SpanIsFullException : public std::exception {
	public:
		char const*	what() const noexcept override;
	};

	class SpanTooSmallException : public std::exception {
	public:
		explicit	SpanTooSmallException(std::string const& functionCalled);
		char const* what() const noexcept override;

	private:
		std::string	_functionCalled;
	};
};


#endif //CPP08_SPAN_HPP
