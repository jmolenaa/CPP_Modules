/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:14 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:14 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#include "Ice.hpp"
#include <iostream>
#include "defines.h"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &src) : AMateria(src.getType()){
}

Ice &Ice::operator=(const Ice &rhs) {
	if (this != &rhs) {
		this->setType(rhs.getType());
	}
	return *this;
}

//Ice::~Ice() {
//}

AMateria *Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
