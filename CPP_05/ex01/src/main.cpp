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

int	main() {

	{
		std::cout << BLUE << "\nCreating form with out of range grades, too low and too high\n\n" << RESET;
		try {
			Form	a("Birth certificate", 151, 10);
		}
		catch (std::exception& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			Form	a("Birth certificate", 0, 10);
		}
		catch (std::exception& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			Form	a("Birth certificate", 10, 151);
		}
		catch (std::exception& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			Form	a("Birth certificate", 10, 0);
		}
		catch (std::exception& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			Form	a("Birth certificate", -100, 10);
		}
		catch (std::exception& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			Form	a("Birth certificate", 10, 10000);
		}
		catch (std::exception& e) {
			std::cout << RED << e.what() << RESET;
		}

		try {
			Form	a("Birth certificate", -12310, 14444);
		}
		catch (std::exception& e) {
			std::cout << RED << e.what() << RESET;
		}
	}

	{
		std::cout << BLUE << "\nCreating a form, testing the insertion overload, getters and the besigned function\n\n" << RESET;

		Form	a("Drivers license", 100, 50);

		std::cout << a;
		std::cout << a.getName() << "\n";
		std::cout << a.getExecuteGrade() << "\n";
		std::cout << a.getSignGrade() << "\n";
		std::cout << a.getIsSigned() << "\n";

		Bureaucrat	b("Bruce", 101);

		try {
			a.beSigned(b);
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << "this won't work\n";
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << RED << e.what() << RESET;
		}
//		catch (std::exception& e) {
//			std::cout << "This one would\n";
//		}
		std::cout << BLUE << "\nIncrementing, trying again and then trying again on a signed form\n\n" << RESET;
		b.incrementGrade();
		a.beSigned(b);
		std::cout << a.getIsSigned() << "\n";
		try {
			a.beSigned(b);
		}
		catch (Form::FormAlreadySignedException& e) {
			std::cout << RED << e.what() << RESET;
		}
		std::cout << "\n";

	}
	{
		std::cout << BLUE << "\nUsing the bureaucrats signform function\n\n" << RESET;

		Form	a("Execution form", 100, 50);
		Bureaucrat	b("Mort", 101);

		b.signForm(a);
		b.incrementGrade();
		b.signForm(a);
		std::cout << a.getIsSigned() << "\n";
		b.signForm(a);
		std::cout << "\n";

	}
}
