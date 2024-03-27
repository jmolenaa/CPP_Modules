/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:09:36 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:09:36 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "AAnimal.hpp"
#include <iostream>
#include "defines.h"

AAnimal::AAnimal() : _type("AAnimal"){
	std::cout << YELLOW << "AAnimal default created\n" << RESET;
}

AAnimal::AAnimal(const AAnimal &src) : _type(src.getType()){
	std::cout << YELLOW << "AAnimal copy created\n" << RESET;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	std::cout << YELLOW << "AAnimal assigned\n" << RESET;
	if (this != &rhs) {
		this->setType(rhs.getType());
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << YELLOW << "AAnimal disintegrated\n" << RESET;
}

std::string AAnimal::getType() const {
	return (this->_type);
}

void AAnimal::setType(std::string type) {
	this->_type = std::move(type);
}
