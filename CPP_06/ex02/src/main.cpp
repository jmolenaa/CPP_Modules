/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 12:12:03 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/10 12:12:03 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "defines.h"
#include <iostream>

int	main() {

	std::cout << BLUE << "Identifying\n\n" << RESET;

	for (int i = 0; i < 10; i++) {
		Base*	someBase = generate();
		std::cout << BLUE << "By reference\n" << RESET;
		identify(*someBase);
		std::cout << BLUE << "By pointer\n" << RESET;
		identify(someBase);
		std::cout << "\n";
		delete someBase;
	}

	std::cout << BLUE << "Identifying garbage\n\n" << RESET;

	identify(nullptr);
	Base	someBase;
	identify(someBase);
	identify(&someBase);
}

