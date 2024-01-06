/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:12:56 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 13:12:59 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << name << " was born and chose " << weapon.getType() << " as it's starting weapon\n";
}

HumanA::~HumanA() {
	std::cout << this->_name << " has met it's demise\n";
}

void HumanA::attack() const {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "\n";
}
