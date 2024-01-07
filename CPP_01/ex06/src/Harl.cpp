/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:02:53 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/07 14:02:54 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	std::cout << "Harl has entered the restaurant\n";
}

Harl::~Harl() {
	std::cout << "Harl has finally left\n";
}

void Harl::debug(void) const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\n"
				 "ketchup burger. I really do!\n";
}

void Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\n"
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\n"
				 "years whereas you started working here since last month.\n";
}

void Harl::error(void) const {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}


void Harl::complain(std::string level) const {
	switch (level[0]) {

		case 'D':
			this->debug();
			[[fallthrough]];
		case 'I':
			this->info();
			[[fallthrough]];
		case 'W':
			this->warning();
			[[fallthrough]];
		case 'E':
			this->error();
			break;
//		default:
//			std::cerr << "Incorrect input\n";
	}
}
