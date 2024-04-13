/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/13 11:46:28 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/13 11:46:28 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 13-4-24.
//

#ifndef CPP_07_ARRAY_HPP
#define CPP_07_ARRAY_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class Array {

private:
	size_t	_size;
	T*		_arr;

public:

	Array<T>() : _size(0) {
		this->_arr = new T[this->size()];
	}

	Array<T>(Array<T> const& src) : _size(src.size()) {
		this->_arr = new T[src.size()];
		for (size_t i = 0; i < src.size(); ++i) {
			(*this)[i] = src[i];
		}
	}

	explicit Array<T>(unsigned int n) : _size(n) {
		this->_arr = new T[this->size()];
		for (size_t i = 0; i < this->size(); ++i) {
			(*this)[i] = T();
		}
	}

	Array<T>&	operator=(Array<T> const& rhs) {
		if (this != &rhs) {
			this->_size = rhs.size();
			delete [] this->_arr;
			this->_arr = new T[rhs.size()];
			for (size_t i = 0; i < rhs.size(); ++i) {
				(*this)[i] = rhs[i];
			}
		}
		return *this;
	}

	~Array<T>() {
		delete [] this->_arr;
	}

	T&	operator[](size_t i) {
		if (i >= this->size()) {
			throw std::out_of_range("Index out of bounds");
		}
		return this->_arr[i];
	}

	T const&	operator[](size_t i) const {
		if (i >= this->size()) {
			throw std::out_of_range("Index out of bounds");
		}
		return this->_arr[i];
	}

	size_t	size() const {
		return this->_size;
	}
};

template <typename T>
std::ostream&	operator<<(std::ostream& outstream, Array<T> array) {
	for (size_t i = 0; i < array.size(); ++i) {
		outstream << array[i] << " ";
	}
	outstream << "\n";
	return outstream;
}

#endif //CPP_07_ARRAY_HPP
