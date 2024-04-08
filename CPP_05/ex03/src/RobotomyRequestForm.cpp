/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:37:37 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/04 16:37:37 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 4-4-24.
//

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include "defines.h"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Marvin"){
	std::cout << "Default robotomy created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src){
	this->_target = src.getTarget();
	std::cout << "Copied robotomy\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	std::cout << "Assigned robotomy\n";
	if (this != &rhs) {
		this->AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(std::move(target)){
	std::cout << "Parameterized robotomy made\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy destroyed\n";
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::_executeForm() const {
	std::cout << "*Drilling noises*\n";
	srand(clock());
	if (rand() % 2 == 1) {
		std::cout << GREEN << this->getTarget() << " has been successfully robotomized\n" << RESET;
	}
	else {
		std::cout << RED << "The robotomy on " << this->getTarget() << " has failed\n" << RESET;
	}
}
