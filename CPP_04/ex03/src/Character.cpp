/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:08 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:08 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#include "Character.hpp"
#include <iostream>
#include "defines.h"

// TODO
// noexcept thing

Character::Character() {

}

Character::Character(const Character &src) {

}

Character &Character::operator=(const Character &rhs) {

}

Character::~Character() noexcept {

}

const std::string &Character::getName() const {

}

void Character::equip(AMateria *m) {

}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter &target) {

}
