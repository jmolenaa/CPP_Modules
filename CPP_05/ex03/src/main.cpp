/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 08:15:13 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/02 08:15:13 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "defines.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {

	Intern		a;
	Bureaucrat	Chad("Chad", 1);

	std::cout << BLUE << "\nShrubbery\n" << RESET;
	AForm*	someForm = a.makeForm("ShrubberyCreationForm", "Knights of Ni");
	std::cout << "\n";
	Chad.signForm(*someForm);
	Chad.executeForm(*someForm);
	delete someForm;
	std::cout << BLUE << "\nRobotomy\n" << RESET;
	someForm = a.makeForm("RobotomyRequestForm", "Marvin");
	std::cout << "\n";
	Chad.signForm(*someForm);
	Chad.executeForm(*someForm);
	delete someForm;
	std::cout << BLUE << "\nPardon\n" << RESET;
	someForm = a.makeForm("PresidentialPardonForm", "Arthur Dent");
	std::cout << "\n";
	Chad.signForm(*someForm);
	Chad.executeForm(*someForm);
	delete someForm;
	std::cout << BLUE << "\nForm that doesn't exist\n" << RESET;
	someForm = a.makeForm("???", "Arthur Dent");
	std::cout << someForm << "\n\n";
}
