/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:13:10 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 13:13:11 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std :: string type) : _type(type) {
	std::cout<< type << " constructed\n";
}


Weapon::~Weapon() {
	std::cout<<this->_type<<" destroyed\n";
}

const std::string& Weapon::getType() const{
	return this->_type;
}

void Weapon::setType(std::string newType) {
	this->_type = newType;
}
