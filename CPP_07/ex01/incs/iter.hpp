/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 14:00:56 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/12 14:00:56 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 12-4-24.
//

#ifndef CPP_07_ITER_HPP
#define CPP_07_ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T* array, size_t arrSize, void (*func)(T&)) {

	if (func != nullptr) {
		for (size_t i = 0; i < arrSize; ++i) {
			func(array[i]);
		}
	}
}

#endif //CPP_07_ITER_HPP
