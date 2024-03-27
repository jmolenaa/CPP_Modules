/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:09:50 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:09:50 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"
#include "defines.h"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("Human") {
	std::cout << RED << "Human default created\n" << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src.get_type()){
	std::cout << RED << "Human copy created\n" << RESET;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << RED << "Human assigned\n" << RESET;
	if (this != &rhs) {
		this->setType(rhs.get_type());
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "Human died to some stupid stuff probably\n" << RESET;
}

void WrongAnimal::makeSound() const {
	std::cout << RED << "Probably some stuff about bitcoin or whatever\n" << RESET;
}

void WrongAnimal::setType(std::string type) {
	this->_type = std::move(type);
}

std::string WrongAnimal::get_type() const {
	return (this->_type);
}
