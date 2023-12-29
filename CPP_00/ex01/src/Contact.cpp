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
#include <iostream>

//Contact :: Contact () {}

//Contact::~Contact() {}

bool Contact::setFirstName() {
	getline(std::cin, this->_firstName);
	if (this->_firstName.empty() && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setLastName() {
	getline(std::cin, this->_lastName);
	if (this->_lastName.empty() && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setNickName() {
	getline(std::cin, this->_nickName);
	if (this->_nickName.empty() && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setPhoneNumber() {
	getline(std::cin, this->_phoneNumber);
	if ((this->_phoneNumber.empty() ||
		this->_phoneNumber.find_first_not_of("+0123456789") != std::string::npos ||
		this->_phoneNumber.find_first_not_of("0123456789", 1) != std::string::npos ||
		this->_phoneNumber.length() < 7 || this->_phoneNumber.length() > 15) && !std::cin.eof())
		return false;
	return true;
}

bool Contact::setDarkestSecret() {
	getline(std::cin, this->_darkestSecret);
	if (this->_darkestSecret.empty() && !std::cin.eof())
		return false;
	return true;
}
