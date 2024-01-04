/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:50 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/04 11:27:53 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	std :: cout << "Some noname NPC has been infected\n";
}

Zombie::Zombie(std::string const name) : _name(name) {

	std :: cout << this->_name << " has been infected\n";

}

Zombie::~Zombie() {

	std :: cout << this->_name << " had it's brains blown out\n";

}

void Zombie::announce() const {

	std :: cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";

}

void	Zombie :: setName(std :: string name){
	this->_name = name;
}
