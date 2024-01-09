/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:13:05 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 13:13:06 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std :: string& name) : _name(name), _weapon(nullptr) {
	std::cout << name << " was born\n";
}

HumanB::~HumanB() {
	std::cout << this->_name << " has met it's demise\n";
}

void HumanB::attack() const {
	if (this->_weapon == nullptr)
		std::cout << this->_name << " flails wildly\n";
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
