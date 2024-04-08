/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:37:36 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/04 16:37:36 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 4-4-24.
//

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("forest") {
	std::cout << "Default shrubbery created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {
	this->_target = src.getTarget();
	std::cout << "Copied shrubbery\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	std::cout << "Assigned shrubbery\n";
	if (this != &rhs) {
		this->AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destroyed\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(std::move(target)) {
	std::cout << "Parameterized shrubbery made\n";
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::_executeForm() const {

	std::ofstream	shrubbery(this->getTarget() + "_shrubbery");

	if (shrubbery.is_open() == false) {
		std::cerr << "Error opening file\n";
		return ;
	}
	shrubbery << "\n"
				 "                      ___\n"
				 "                _,-'\"\"   \"\"\"\"`--.\n"
				 "             ,-'          __,,-- \\\n"
				 "           ,'    __,--\"\"\"\"dF      )\n"
				 "          /   .-\"Hb_,--\"\"dF      /\n"
				 "        ,'       _Hb ___dF\"-._,-'\n"
				 "      ,'      _,-\"\"\"\"   \"\"--..__\n"
				 "     (     ,-'                  `.\n"
				 "      `._,'     _   _             ;\n"
				 "       ,'     ,' `-'Hb-.___..._,-'\n"
				 "       \\    ,'\"Hb.-'HH`-.dHF\"\n"
				 "        `--'   \"Hb  HH  dF\"\n"
				 "                \"Hb HH dF\n"
				 "                 \"HbHHdF\n"
				 "                  |HHHF\n"
				 "                  |HHH|\n"
				 "                  |HHH|\n"
				 "                  |HHH|\n"
				 "                  |HHH|\n"
				 "                  dHHHb\n"
				 "                .dFd|bHb.               o\n"
				 "      o       .dHFdH|HbTHb.          o /\n"
				 "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
				 "##########################################";
	shrubbery.close();
}
