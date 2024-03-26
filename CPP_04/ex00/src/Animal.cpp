/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:09:36 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:09:36 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include <iostream>
#include "defines.h"

Animal::Animal() : _type("Cockroach"){
	std::cout << YELLOW << "Cockroach default created\n" << RESET;
}

Animal::Animal(const Animal &src) : _type(src.getType()){
	std::cout << YELLOW << "Cockroach copy created\n" << RESET;
}

Animal &Animal::operator=(const Animal &rhs) {
	std::cout << YELLOW << "Cockroach assigned\n" << RESET;
	if (this != &rhs) {
		this->setType(rhs.getType());
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << YELLOW << "Cockroach disintegrated\n" << RESET;
}

void Animal::makeSound() const {
	std::cout << YELLOW << "* scuttling noises *\n" << RESET;
}

std::string Animal::getType() const {
	return (this->_type);
}

void Animal::setType(std::string type) {
	this->_type = std::move(type);
}
