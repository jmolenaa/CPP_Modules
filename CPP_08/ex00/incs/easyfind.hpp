/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 13:42:52 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/04 13:42:52 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template<typename T>
auto	easyFind(T & container, int value) -> decltype(container.begin()) {
	auto it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		std::cout << "Could not find value in range\n";
	}
	else {
		std::cout << "Found value in spot: " << std::distance(container.begin(), it) << "\n";
	}
	return (it);
}

#endif
