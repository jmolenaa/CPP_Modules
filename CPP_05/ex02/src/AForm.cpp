/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
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

#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("random form"), _signGrade(150), _executeGrade(150) {
	std::cout << "Default form made\n";
}

AForm::AForm(const AForm &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()) {
	std::cout << "AForm copied\n";
	_checkGrades();
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(std::move(name)), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "Parameterized form created\n";
	_checkGrades();
}

AForm &AForm::operator=(const AForm &rhs) {
	std::cout << "Assigned bureaucrat\n";
	if (this != &rhs) {
		this->_isSigned = rhs.getIsSigned();
		_checkGrades();
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructed\n";
}

std::string AForm::getName() const {
	return this->_name;
}

int AForm::getExecuteGrade() const {
	return this->_executeGrade;
}

int AForm::getSignGrade() const {
	return this->_signGrade;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

void AForm::_checkGrades() const {
	if (this->getSignGrade() < 1 || this->getExecuteGrade() < 1) {
		throw GradeTooHighException();
	}
	if (this->getSignGrade() > 150 || this->getExecuteGrade() > 150) {
		throw GradeTooLowException();
	}
}

void AForm::beSigned(const Bureaucrat &signee) {
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

void AForm::execute(const Bureaucrat &executor) const {
	if (this->getIsSigned() == false) {
		throw FormNotSignedException();
	}
	if (this->getExecuteGrade() < executor.getGrade()) {
		throw GradeTooLowException();
	}
	this->_executeForm();
}

const char *AForm::GradeTooLowException::what() const noexcept {
	return ("Grade is too low\n");
}

const char *AForm::GradeTooHighException::what() const noexcept {
	return ("Grade is too high\n");
}

const char *AForm::FormAlreadySignedException::what() const noexcept {
	return ("Form was already signed\n");
}

const char *AForm::FormNotSignedException::what() const noexcept {
	return ("Form hasn't been signed\n");
}

std::ostream&	operator<<(std::ostream& outstream, AForm const& rhs) {
	outstream << "AForm name: " << rhs.getName() << " ,sign grade: " << rhs.getSignGrade() << " ,execute grade: " << rhs.getExecuteGrade() << " ,and is signed: " << rhs.getIsSigned() << "\n";
	return outstream;
}

