/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/13 10:54:36 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/13 10:54:36 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "ArrayTppImplemented.hpp"

template <typename T>
Array<T>::Array() : _size(0){
	this->_arr = new T[this->_size];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n){
	this->_arr = new T[this->_size];
}

template <typename T>
Array<T>::Array(const Array<T> &src) : _size(src.size()) {
	this->_arr = new T[src.size()];
	for (size_t i = 0; i < src.size(); ++i) {
		(*this)[i] = src[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] this->_arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs) {

	if (this != &rhs) {
		this->_size = rhs.size();
		delete [] this->_arr;
		this->_arr = new T(rhs._size);
		for (size_t i = 0; i < rhs.size(); ++i) {
			(*this)[i] = rhs[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](size_t i){
	if (i >= this->size()) {
		throw std::out_of_range("Index is out of range");
	}
	return this->_arr[i];
}

template <typename T>
const T &Array<T>::operator[](size_t i) const {
	if (i >= this->size()) {
		throw std::out_of_range("Index is out of range");
	}
	return this->_arr[i];
}

template <typename T>
size_t Array<T>::size() const {
	return this->_size;
}

template <typename T>
std::ostream&	operator<<(std::ostream &outstream, Array<T> array) {
	for (size_t i = 0; i < array.size(); ++i) {
		outstream << array[i] << " ";
	}
	outstream << "\n";
	return outstream;
}

#endif