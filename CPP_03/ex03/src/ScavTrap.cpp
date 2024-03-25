/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 16:36:17 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 16:36:17 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	this->_name = "jACK";
	this->_hp = ScavTrap::_initHp;
	this->_ad = ScavTrap::_initAd;
	this->_ep = ScavTrap::_initEp;
	this->_maxHp = ScavTrap::_initHp;
	std::cout << "SCAVTRAP DEFAULT CONSTRUCTOR CALLED\n";
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src){
	std::cout << "SCAVTRAP COPY CONSTRUCTOR CALLED\n";
}

ScavTrap::ScavTrap(const std::string &name) {
	this->_name = name;
	this->_hp = ScavTrap::_initHp;
	this->_ad = ScavTrap::_initAd;
	this->_ep = ScavTrap::_initEp;
	this->_maxHp = ScavTrap::_initHp;
	std::cout << "SCAVTRAP PARAMETERIZED CONSTRUCTOR CALLED\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "SCAVTRAP DESTRUCTOR CALLED\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "SCAVTRAP ASSIGNMENT OPERATOR CALLED\n";
	if (this == &rhs) {
		return (*this);
	}
	ClapTrap::operator=(rhs);
	return (*this);
}

void ScavTrap::guardGate() {
	if (this->_hp == 0){
		std::cout << "Scavtrap is dead and can't guard anything\n";
	}
	else if (this->_ep == 0){
		std::cout << "Scavtrap has no energy left and can't guard anything\n";
	}
	else {
		std::cout << "Guarding the bridge of Khazad-Dum\n";
	}
}

void ScavTrap::attack(const std::string &target) {
	if (this->_ep > 0 && this->_hp > 0) {
		std::cout << "SCAVTRAP " << this->_name << " ATTACKS " << target << " DEALING " << this->_ad << " DAMAGE\n";
		--this->_ep;
	}
	else if (this->_ep == 0) {
		std::cout << "NO ENERGY LOL, CANNOT ATTACK\n";
	}
	else {
		std::cout << "SCAVTRAP DEAD LOL, CANNOT ATTACK\n";
	}
}
