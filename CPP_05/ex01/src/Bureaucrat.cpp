/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 08:16:04 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/02 08:16:04 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 2-4-24.
//

#include "Bureaucrat.hpp"
#include <iostream>
#include "defines.h"

// TODO
// ask Laura about the throw() thingy
Bureaucrat::Bureaucrat() : _name("NPC"), _grade(150){
	std::cout << "Default Bureaucrat made\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()) {
	std::cout << "Copied Bureaucrat\n";
	this->setGrade(src.getGrade());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {

	std::cout << "Assigned bureaucrat\n";
	if (this != &rhs) {
		this->setGrade(rhs.getGrade());
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(std::move(name)) {
	std::cout << "Parameterized bureaucrat made\n";
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destroyed\n";
}


int Bureaucrat::getGrade() const {
	return this->_grade;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

void Bureaucrat::setGrade(int newGrade) {
	if (newGrade > 150) {
		this->_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (newGrade < 1) {
		this->_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade = newGrade;
}

void Bureaucrat::incrementGrade() {
	this->setGrade(--this->_grade);

}

void Bureaucrat::decrementGrade() {
	this->setGrade(++this->_grade);
}

void Bureaucrat::signForm(Form &formToSign) const{
	try {
		formToSign.beSigned(*this);
		std::cout << this->getName() << " signed " << formToSign.getName() << "\n";
	}
	catch (std::exception& e) {
		std::cout << RED << this->getName() << " couldn't sign " << formToSign.getName() << " because " << e.what() << RESET;
	}
}

std::ostream&	operator<<(std::ostream& outstream, Bureaucrat const& rhs) {
	outstream << rhs.getName() << " bureaucrat with grade: " << rhs.getGrade() << "\n";
	return outstream;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Grade is too high, (< 1)\n");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Grade is too low, (> 150)\n");
}
