/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:09:54 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:09:54 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"
#include "defines.h"
#include <iostream>

WrongCat::WrongCat() {
	std::cout << BLUE << "Fox default created\n" << RESET;
	this->setType("Fox");
	this->headGlobes = new Brain();
}

WrongCat::WrongCat(const WrongCat &src) {
	std::cout << BLUE << "Fox copy created\n" << RESET;
	this->setType(src.get_type());
	this->headGlobes = new Brain(*src.headGlobes);
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	std::cout << BLUE << "Fox assigned\n" << RESET;
	if (this == &rhs) {
		this->setType(rhs.get_type());
		delete this->headGlobes;
		this->headGlobes = new Brain(*rhs.headGlobes);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << BLUE << "Fox ate a poisoned chicken\n" << RESET;
	delete this->headGlobes;
}

void WrongCat::makeSound() const {
	std::cout << BLUE << "What does the fox say?\n" << RESET;
}
