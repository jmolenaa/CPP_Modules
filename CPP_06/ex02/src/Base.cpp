/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 12:12:04 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/10 12:12:04 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 10-4-24.
//

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include "defines.h"

Base*	generate() {
	srand(clock());

	switch (rand() % 3) {
		case 0:
			std::cout << "(created class A)\n";
			return new A();
		case 1:
			std::cout << "(created class B)\n";
			return new B();
		case 2:
			std::cout << "(created class C)\n";
			return new C();
		default:
			return nullptr;
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "Object pointed to by p is of class A\n";
	}
	else if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "Object pointed to by p is of class B\n";
	}
	else if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "Object pointed to by p is of class C\n";
	}
	else {
		std::cout << RED << "Some garbage sent in\n"<< RESET;
	}
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Object pointed to by p is of class A\n";
	}
	catch (std::bad_cast& e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "Object pointed to by p is of class B\n";
		}
		catch (std::bad_cast& e) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "Object pointed to by p is of class C\n";
			}
			catch (std::bad_cast& e) {
				std::cout << RED << "Some garbage sent in\n"<< RESET;
			}
		}
	}

}
