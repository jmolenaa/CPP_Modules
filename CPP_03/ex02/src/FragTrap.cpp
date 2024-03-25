/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 09:25:37 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/25 09:25:37 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	this->_name = "Tina";
	this->_hp = 100;
	this->_ad = 30;
	this->_ep = 100;
	this->_maxHp = 100;
	std::cout << "fragtrap DEFAULT constructor CALLED\n";
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src){
	std::cout << "fragtrap COPY constructor CALLED\n";
}

FragTrap::FragTrap(const std::string &name) {
	this->_name = name;
	this->_hp = 100;
	this->_ad = 30;
	this->_ep = 100;
	this->_maxHp = 100;
	std::cout << "fragtrap PARAMETERIZED constructor CALLED\n";
}

FragTrap::~FragTrap() {
	std::cout << "fragtrap DESTRUCTOR called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "fragtrap ASSIGNMENT operator CALLED\n";
	if (this == &rhs) {
		return (*this);
	}
	ClapTrap::operator=(rhs);
	return (*this);
}

void FragTrap::highFivesGuys() {
	if (this->_hp == 0){
		std::cout << "Fragtrap is dead and can't put their hand up\n";
	}
	else if (this->_ep == 0){
		std::cout << "Fragtrap has no energy left and can't put their hand up\n";
	}
	else {
		std::cout << "Gib high fives :)\n";
	}
}

void FragTrap::attack(const std::string &target) {
	if (this->_ep > 0 && this->_hp > 0) {
		std::cout << "fragtrap " << this->_name << " ATTACKS " << target << " dealing " << this->_ad << " DAMAGE\n";
		--this->_ep;
	}
	else if (this->_ep == 0) {
		std::cout << "no ENERGY lol, CANNOT attack\n";
	}
	else {
		std::cout << "fragtrap DEAD lol, CANNOT attack\n";
	}
}

