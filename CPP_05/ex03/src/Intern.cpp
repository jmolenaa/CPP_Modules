/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 07:24:23 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/08 07:24:23 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 8-4-24.
//

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "defines.h"

AForm	*shrubbery(std::string target) {
	return (new ShrubberyCreationForm(std::move(target)));
}

AForm	*robotomy(std::string target) {
	return (new RobotomyRequestForm(std::move(target)));
}

AForm	*pardon(std::string target) {
	return (new PresidentialPardonForm(std::move(target)));
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	AForm*	newForm;

	std::string	formNames[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*	(*createForm[])(std::string) = {shrubbery, robotomy, pardon};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			newForm = createForm[i](target);
			std::cout << "Intern creates " << formNames[i] << "\n";
			return newForm ;
		}
	}
	std::cout << RED << formName << " doesn't exist\n" << RESET;
	return nullptr;
}
