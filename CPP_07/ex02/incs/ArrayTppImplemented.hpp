/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 16:58:25 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/12 16:58:25 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 12-4-24.
//

#ifndef CPP_07_ARRAYTPPIMPLEMENTED_HPP
#define CPP_07_ARRAYTPPIMPLEMENTED_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class Array {

private:
	size_t	_size;
	T*		_arr;

public:

	Array();
	Array(Array const& src);
	Array&	operator=(Array const& rhs);
	explicit Array(unsigned int n);
	~Array();

	T&	operator[](size_t i);
	T const&	operator[](size_t i) const;
	size_t	size() const;

};

template <typename T>
std::ostream&	operator<<(std::ostream& outstream, Array<T> array);

#include "Array.tpp"

#endif //CPP_07_ARRAYTPPIMPLEMENTED_HPP
