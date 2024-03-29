/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:03 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:03 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#include "MateriaSource.hpp"
#include <iostream>
#include "defines.h"

//MateriaSource::MateriaSource() {
//
//}

MateriaSource::MateriaSource(const MateriaSource &src) : _alreadyKnown(src._alreadyKnown){
	for (size_t i = 0; i < 4 && src._learntMaterias[i] != nullptr; ++i) {
		this->_learntMaterias[i] = src._learntMaterias[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		this->_alreadyKnown = rhs._alreadyKnown;
		for (size_t i = 0; i < 4 && this->_learntMaterias[i] != nullptr; ++i) {
			delete this->_learntMaterias[i];
			this->_learntMaterias[i] = nullptr;
		}
		for (size_t i = 0; i < 4 && rhs._learntMaterias[i] != nullptr; ++i) {
			this->_learntMaterias[i] = rhs._learntMaterias[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4 && this->_learntMaterias[i] != nullptr; ++i) {
		delete this->_learntMaterias[i];
	}
}

void MateriaSource::learnMateria(AMateria *newMateria) {
	if (this->_alreadyKnown == 4) {
		std::cout << "Can't learn more :(\n";
		return ;
	}
	if (newMateria == nullptr) {
		std::cout << "Please give a valid materia\n";
		return ;
	}

	this->_learntMaterias[_alreadyKnown] = newMateria->clone();
	this->_alreadyKnown++;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (size_t i = 0; i < this->_alreadyKnown; ++i) {
		if (this->_learntMaterias[i]->getType() == type) {
			return (this->_learntMaterias[i]->clone());
		}
	}
	std::cout << "Materia hasn't been learnt\n";
	return (nullptr);
}
