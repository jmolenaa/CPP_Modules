/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:11 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:11 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#include "Cure.hpp"
#include <iostream>
#include "defines.h"

Cure::Cure() : AMateria("cure"){

}

Cure::Cure(const Cure &src) : AMateria(src.getType()){
}

Cure &Cure::operator=(const Cure &rhs) {
	if (this != &rhs) {
		this->setType(rhs.getType());
	}
	return *this;
}

//Cure::~Cure() {
//
//}

AMateria *Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
