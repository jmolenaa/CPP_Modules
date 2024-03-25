/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:37:32 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 10:37:32 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Jack"), _hp(ClapTrap::_initHp), _ep(ClapTrap::_initEp), _ad(ClapTrap::_initAd), _maxHp(ClapTrap::_initHp){
	std::cout << "Claptrap default constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap const& src) : _name(src._name), _hp(src._hp), _ep(src._ep), _ad(src._ad), _maxHp(src._maxHp){
	std::cout << "Claptrap copy constructor called\n";
}

ClapTrap::ClapTrap(std::string const& name) : _name(name), _hp(ClapTrap::_initHp), _ep(ClapTrap::_initEp), _ad(ClapTrap::_initAd), _maxHp(ClapTrap::_initHp) {
	std::cout << "Claptrap parameterized constructor called\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap destructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	std::cout << "Claptrap assignment operator called\n";
	if (this == &rhs) {
		return (*this);
	}
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ad = rhs._ad;
	this->_ep = rhs._ep;
	this->_maxHp = rhs._maxHp;
	return (*this);
}

void ClapTrap::attack(const std::string &target) {
	if (this->_ep > 0 && this->_hp > 0) {
		std::cout << "Claptrap " << this->_name << " attacks " << target << " dealing " << this->_ad << " damage\n";
		--this->_ep;
	}
	else if (this->_ep == 0) {
		std::cout << "No energy lol, cannot attack\n";
	}
	else {
		std::cout << "Claptrap dead lol, cannot attack\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0) {
		std::cout << "He's already dead :(\n";
	}
	else {
		if ((unsigned int)this->_hp < amount || amount > this->_maxHp) {
			amount = this->_hp;
		}
		std::cout << this->_name << " takes " << amount << " damage\n";
		this->_hp -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_ep > 0 && this->_hp > 0) {
		if (amount + this->_hp > this->_maxHp){
			amount = 10 - this->_hp;
		}
		std::cout << this->_name << " heals for " << amount << " hit points\n";
		--this->_ep;
		this->_hp += amount;
	}
	else if (this->_ep == 0) {
		std::cout << "No energy lol, cannot be repaired\n";
	}
	else {
		std::cout << this->_name << " is dead lol, cannot be repaired\n";
	}
}

void	ClapTrap::printClaptrap() {
	std::cout << this->_name << " has " << this->_hp << " health, " << this->_ep << " energy and " << this->_ad << " attack damage\n";
}
