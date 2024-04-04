/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 10:13:39 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/02 10:13:39 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 2-4-24.
//

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("random form"), _signGrade(150), _executeGrade(150) {
	std::cout << "Default form made\n";
}

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()) {
	std::cout << "Form copied\n";
	_checkGrades();
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(std::move(name)), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "Parameterized form created\n";
	_checkGrades();
}

Form &Form::operator=(const Form &rhs) {
	std::cout << "Assigned bureaucrat\n";
	if (this != &rhs) {
		this->_isSigned = rhs.getIsSigned();
		_checkGrades();
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form destructed\n";
}

std::string Form::getName() const {
	return this->_name;
}

int Form::getExecuteGrade() const {
	return this->_executeGrade;
}

int Form::getSignGrade() const {
	return this->_signGrade;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

void Form::_checkGrades() const {
	if (this->getSignGrade() < 1 || this->getExecuteGrade() < 1) {
		throw GradeTooHighException();
	}
	if (this->getSignGrade() > 150 || this->getExecuteGrade() > 150) {
		throw GradeTooLowException();
	}
}

void Form::beSigned(const Bureaucrat &signee) {
	if (this->getSignGrade() < signee.getGrade()) {
		throw GradeTooLowException();
	}
	if (this->getIsSigned() == true) {
		throw FormAlreadySignedException();
	}
	else {
		this->_isSigned = true;
	}
}

const char *Form::GradeTooLowException::what() const noexcept {
	return ("Grade is too low\n");
}

const char *Form::GradeTooHighException::what() const noexcept {
	return ("Grade is too high\n");
}

const char *Form::FormAlreadySignedException::what() const noexcept {
	return ("Form was already signed\n");
}

std::ostream&	operator<<(std::ostream& outstream, Form const& rhs) {
	outstream << "Form name: " << rhs.getName() << " ,sign grade: " << rhs.getSignGrade() << " ,execute grade: " << rhs.getExecuteGrade() << " ,and is signed: " << rhs.getIsSigned() << "\n";
	return outstream;
}

