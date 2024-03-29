/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Floor.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 11:08:16 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/28 11:08:16 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 28-3-24.
//

#include "Floor.hpp"

Floor::Floor() {
	this->floorClutter = new AMateria*[currentCapacity] {nullptr};
}

Floor::~Floor() {
	for (size_t i = 0; i < this->currentCapacity; ++i) {
		delete this->floorClutter[i];
	}
	delete [] this->floorClutter;
}

Floor &Floor::getFloor() {
	static Floor floor;
	return floor;
}

void Floor::increaseCapacity() {
	AMateria** newClutter = new AMateria*[this->currentCapacity + 10] {nullptr};
	for (size_t i = 0; i < this->currentItems; ++i) {
		newClutter[i] = this->floorClutter[i];
	}
	delete [] this->floorClutter;
	this->floorClutter = newClutter;
	this->currentCapacity += 10;
}

void Floor::addToFloor(AMateria *toAdd) {
	if (this->currentItems == this->currentCapacity) {
		this->increaseCapacity();
	}
	this->floorClutter[currentItems] = toAdd;
	this->currentItems++;
}
