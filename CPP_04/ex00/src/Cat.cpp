/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:09:46 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:09:46 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "defines.h"
#include <iostream>

Cat::Cat() {
	std::cout << CYAN << "Cat default created\n" << RESET;
	this->setType("Cat");
}

Cat::Cat(const Cat &src) {
	std::cout << CYAN << "Cat copy created\n" << RESET;
	this->setType(src.getType());
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << CYAN << "Cat assigned\n" << RESET;
	if (this != &rhs) {
		this->setType(rhs.getType());
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << CYAN << "Cat thrown to the dogs\n" << RESET;
}

void Cat::makeSound() const {
	std::cout << CYAN << "I am purrfectly sane today\n" << RESET;
}
