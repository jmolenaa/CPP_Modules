/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:37:39 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/04 16:37:39 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 4-4-24.
//

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Arthur Dent"){
	std::cout << "Default pardon created\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src){
	this->_target = src.getTarget();
	std::cout << "Copied pardon\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	std::cout << "Assigned pardon\n";
	if (this != &rhs) {
		this->AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(std::move(target)){
	std::cout << "Parameterized pardon made\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Pardon destroyed\n";
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::_executeForm() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
