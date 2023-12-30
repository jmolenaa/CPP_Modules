/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 13:27:23 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/12/29 13:27:27 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Contact :: Contact () {}

Contact::~Contact() {}

bool Contact::setFirstName() {
	std :: getline(std::cin, this->_firstName);
	if (this->_firstName.empty() && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setLastName() {
	std :: getline(std::cin, this->_lastName);
	if (this->_lastName.empty() && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setNickName() {
	std :: getline(std::cin, this->_nickName);
	if (this->_nickName.empty() && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setPhoneNumber() {
	std :: getline(std::cin, this->_phoneNumber);
	if ((this->_phoneNumber.empty() ||
		this->_phoneNumber.find_first_not_of("+0123456789") != std::string::npos ||
		this->_phoneNumber.find_first_not_of("0123456789", 1) != std::string::npos ||
		this->_phoneNumber.length() < 7 || this->_phoneNumber.length() > 15) && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setDarkestSecret() {
	std :: getline(std::cin, this->_darkestSecret);
	if (this->_darkestSecret.empty() && !std::cin.eof())
		return false;
	return true;
}

static void	displayString(std :: string str) {
	if (str.length() > 10)
		std :: cout << '|' << str.substr(0, 9) << ".";
	else
		std :: cout << '|' << std :: setw(10) << std :: right << str;
}

void Contact::displayContact(int index) {

	std :: cout << std :: setw(46) << std :: setfill('-') << "-\n" << std :: setfill(' ');
	displayString(std ::to_string(index));
	displayString(this->_firstName);
	displayString(this->_lastName);
	displayString(this->_nickName);
	std :: cout << "|\n";
}

void Contact::displayAllInfo() {
	std :: cout	<< "\nFirst name: " << this->_firstName
				<< "\nLast name: " << this->_lastName
				<< "\nNickname: " << this->_nickName
				<< "\nPhone number: " << this->_phoneNumber
				<< "\nDarkest Secret: " << this->_darkestSecret << "\n";
}
