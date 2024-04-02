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
		std::cout << BLUE << "Checking standard consturctor destructor stuff\n\n" << RESET;
		Bureaucrat a;
		Bureaucrat b("Jim", 130);
		Bureaucrat c(b);
		Bureaucrat d;

		d = c;

		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << d;
	}
	{
		std::cout << BLUE << "\nCreating bureaucrats with out of range grade, too low and too high\n\n" << RESET;

		try {
			Bureaucrat	a("Michael", 151);
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}

		try {
			Bureaucrat	a("Michael", 0);
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}

		try {
			Bureaucrat	a("Michael", -100);
			Bureaucrat	b("Michael", 151);
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}

		try {
			Bureaucrat	a("Michael", 100000);
			Bureaucrat	b("Michael", 0);
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << BLUE << "\nTesting the increment function\n\n" << RESET;
		std::cout << BLUE << "\nTesting decrement function\n" << RESET;
		Bureaucrat	a("James", 140);
		std::cout << a;
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		std::cout << a;
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		std::cout << a;
		try {
			a.decrementGrade();
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << BLUE << "\nTesting increment function\n" << RESET;
		Bureaucrat	a("James2", 11
		);
		std::cout << a;
		a.incrementGrade();
		a.incrementGrade();
		a.incrementGrade();
		a.incrementGrade();
		a.incrementGrade();
		std::cout << a;
		a.incrementGrade();
		a.incrementGrade();
		a.incrementGrade();
		a.incrementGrade();
		a.incrementGrade();
		std::cout << a;
		try {
			a.incrementGrade();
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}

	}
}
