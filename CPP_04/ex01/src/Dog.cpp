/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:09:40 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:09:40 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"
#include "defines.h"
#include <iostream>

Dog::Dog() {
	std::cout << GREEN << "Dog default created\n" << RESET;
	this->setType("Dog");
	this->headGlobes = new Brain();
}

Dog::Dog(const Dog &src) {
	std::cout << GREEN << "Dog default created\n" << RESET;
	this->setType(src.getType());
	this->headGlobes = new Brain(*src.headGlobes);
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << GREEN << "Dog assigned\n" << RESET;
	if (this != &rhs) {
		this->setType(rhs.getType());
		delete this->headGlobes;
		this->headGlobes = new Brain(*rhs.headGlobes);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << GREEN << "Dog kicked very hard\n" << RESET;
	delete this->headGlobes;
}

void Dog::makeSound() const {
	std::cout << GREEN << "I've had a ruff day\n" << RESET;
}
