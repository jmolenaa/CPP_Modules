/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 10:20:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/12 10:20:05 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T& a, T& b) {
	T	temp = b;
	b = a;
	a = temp;
}

template<typename T>
T const&	min(T const& first, T const& second) {
	if (first < second) {
		return first;
	}
	return second;
}

template<typename T>
T const&	max(T const& first, T const& second) {
	if (first > second) {
		return first;
	}
	return second;
}
