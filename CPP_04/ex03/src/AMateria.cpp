/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:15 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:15 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#include "AMateria.hpp"
#include <iostream>
#include "defines.h"

//AMateria::AMateria() {
//
//}

//AMateria::AMateria(const AMateria &src) : _type(src._type) {
//
//}

AMateria::AMateria(const std::string& 	type) : _type(type) {

}

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	return (*this);
}

//AMateria::~AMateria() {
//
//}

const std::string &AMateria::getType() const {
	return (this->_type);
}

// TODO
// comment out and see if compiles
void AMateria::use(ICharacter &target) {
	(void)target;
	std::cout << "What am I using on \n";
}
