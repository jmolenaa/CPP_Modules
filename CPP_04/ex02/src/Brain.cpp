/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 12:12:11 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 12:12:11 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "defines.h"

Brain::Brain() {
	std::cout << BLUE << "Default brain constructed\n" << RESET;
	for (int i = 0; i < 100; ++i) {
		this->_ideas[i] = "Gib treats and pets\n";
	}
}

Brain::Brain(const Brain &src) {
	std::cout << BLUE << "Copy of brain constructed\n" << RESET;
	for (int i = 0; i < 100; ++i) {
		this->_ideas[i] = src._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &rhs) {
	std::cout << BLUE << "Brain assigned\n" << RESET;
	if (this != &rhs) {
		for (int i = 0; i < 100; ++i) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << BLUE << "Default brain destructed\n" << RESET;
}
