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

int	main() {

	Bureaucrat	Chad("Chad", 1);

	ShrubberyCreationForm	shrub("Knight of Ni");
	RobotomyRequestForm		robot("Marvin");
	PresidentialPardonForm	pardon("Arthur Dent");

	{
		std::cout << BLUE << "\nTesting unsigned forms\n\n";
		Chad.executeForm(shrub);
		Chad.executeForm(robot);
		Chad.executeForm(pardon);
		try {
			shrub.execute(Chad);
		}
		catch (AForm::FormNotSignedException& e) {
			std::cout<< RED << e.what();
		}

		try {
			robot.execute(Chad);
		}
		catch (AForm::FormNotSignedException& e) {
			std::cout << e.what();
		}

		try {
			pardon.execute(Chad);
		}
		catch (AForm::FormNotSignedException& e) {
			std::cout << e.what() << RESET;
		}
		std::cout << "\n";
	}
	{
		std::cout << BLUE << "\nTesting signing grades\n\n" << RESET;

		Bureaucrat	loser("Loser", 146);
		Bureaucrat	smallerLoser("smallerLoser", 138);
		Bureaucrat	mediumLoser("mediumLoser", 73);
		Bureaucrat	goodLoser("goodLoser", 46);
		Bureaucrat	almostCool("almostCool", 26);
		Bureaucrat	veryCool("veryCool", 6);

		std::cout << "\n";

		try {
			shrub.beSigned(loser);
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			robot.beSigned(mediumLoser);
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			pardon.beSigned(almostCool);
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << RED << e.what() << RESET;
		}

		loser.incrementGrade();
		mediumLoser.incrementGrade();
		almostCool.incrementGrade();

		std::cout << "\nAfter incrementing\n";

		shrub.beSigned(loser);
		robot.beSigned(mediumLoser);
		pardon.beSigned(almostCool);
		std::cout << "\n";

		std::cout << BLUE << "Testing execution grades\n\n";
		try {
			shrub.execute(smallerLoser);
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			robot.execute(goodLoser);
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			pardon.execute(veryCool);
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << RED << e.what() << RESET;
		}

		smallerLoser.executeForm(shrub);
		goodLoser.executeForm(robot);
		veryCool.executeForm(pardon);

		smallerLoser.incrementGrade();
		goodLoser.incrementGrade();
		veryCool.incrementGrade();

		std::cout << "\nAfter incrementing\n";

		smallerLoser.executeForm(shrub);
		shrub.execute(smallerLoser);
		goodLoser.executeForm(robot);
		robot.execute(goodLoser);
		veryCool.executeForm(pardon);
		pardon.execute(veryCool);
		std::cout << "\n";

		std::cout << "\nTesting the 50/50\n\n";
		robot.execute(goodLoser);
		robot.execute(goodLoser);
		robot.execute(goodLoser);
		robot.execute(goodLoser);
		robot.execute(goodLoser);
		robot.execute(goodLoser);
		robot.execute(goodLoser);
		std::cout << "\n";

	}
}
