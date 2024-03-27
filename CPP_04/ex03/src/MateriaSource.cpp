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

MateriaSource::MateriaSource() {

}

MateriaSource::MateriaSource(const MateriaSource &src) {

}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {

}

MateriaSource::~MateriaSource() noexcept {

}

void MateriaSource::learnMateria(AMateria *) {

}

AMateria *MateriaSource::createMateria(const std::string &type) {

}
