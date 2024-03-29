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
#include "Floor.hpp"


Character::Character() : _name("NPC"){
}

Character::Character(const Character &src) : _held_items(src._held_items), _name(src.getName()){
	for (size_t i = 0; i < 4 && src._inventory[i] != nullptr; ++i) {
		this->_inventory[i] = src._inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_held_items = rhs._held_items;
		for (int i = 0; i < 4 && this->_inventory[i] != nullptr; ++i) {
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
		for (int i = 0; i < 4 && rhs._inventory[i] != nullptr; ++i) {
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

Character::Character(std::string name) : _name(std::move(name)){
}

Character::~Character() {
	for (int i = 0; i < 4 && this->_inventory[i] != nullptr; ++i) {
		delete this->_inventory[i];
	}
}

const std::string &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	if (m == nullptr) {
		std::cout << "Cannot equip nullptr dude\n";
		return ;
	}
	if (this->_held_items == 4) {
		std::cout << "Cannot equip more items\n";
		return ;
	}
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == nullptr) {
			this->_inventory[i] = m->clone();
			break ;
		}
	}
	this->_held_items++;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index outside of range\n";
		return ;
	}
	if (this->_inventory[idx] == nullptr) {
		std::cout << "Don't have anything equipped in that slot\n";
		return ;
	}

	Floor::getFloor().addToFloor(this->_inventory[idx]);
	for (size_t i = idx; i < this->_held_items - 1; ++i) {
		this->_inventory[i] = this->_inventory[i + 1];
	}
	this->_held_items--;
	this->_inventory[_held_items] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index outside of range\n";
		return ;
	}
	if (this->_inventory[idx] == nullptr) {
		std::cout << "Don't have anything equipped in that slot\n";
		return ;
	}

	this->_inventory[idx]->use(target);
}
