/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 10:51:07 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/25 10:51:07 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	this->_name = "Zero";
	ClapTrap::_name = "Zero_clap_name";
	this->_hp = FragTrap::_initHp;
	this->_ad = FragTrap::_initAd;
	this->_ep = ScavTrap::_initEp;
	this->_maxHp = FragTrap::_initHp;
	std::cout << "Called default constructor of DiamondTrap\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << "Called copy constructor of DiamondTrap\n";
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(name), FragTrap(name){
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::_initHp;
	this->_ad = FragTrap::_initAd;
	this->_ep = ScavTrap::_initEp;
	this->_maxHp = FragTrap::_initHp;
	std::cout << "Called parameterized constructor of DiamondTrap\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Called destructor of DiamondTrap\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	std::cout << "Called assignment operator of DiamondTrap\n";
	if (this == &rhs) {
		return (*this);
	}
	ClapTrap::operator=(rhs);
	return (*this);
}

void DiamondTrap::whoAmI() {
	if (this->_hp == 0) {
		std::cout << "Dead DiamondTraps don't tell names\n";
	}
	else {
		std::cout << "My name is: " << this->_name;
		std::cout << "\nClaptraps name is: " << ClapTrap::_name << "\n";
	}
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}


