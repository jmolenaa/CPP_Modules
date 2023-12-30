/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 13:27:40 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/12/29 13:27:41 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook() : _phonebookSize(0) {}

Phonebook::~Phonebook() {}

void	Phonebook::_displayAllContacts() {

	std :: cout	<< std :: setw(46) << std :: setfill('-') << "-\n" << std :: setfill(' ')
				   << '|' << std :: setw(10) << std :: right << "index"
				   << '|' << std :: setw(10) << std :: right << "firstname"
				   << '|' << std :: setw(10) << std :: right << "lastname"
				   << '|' << std :: setw(10) << std :: right << "nickname"
				   << "|\n";

	for (int i = 0; i < this->_phonebookSize; i++){
		this->_contacts[i].displayContact(i + 1);
	}

	std :: cout << std :: setw(46) << std :: setfill('-') << "-\n\n" << std :: setfill(' ');
}

int Phonebook::_askForIndex() const {
	std :: string	indexStr;
	int				index;

	while (true){
		std::cout << "Please input an index for the entry you want to display: ";
		std :: getline(std :: cin, indexStr);
		if (std::cin.eof())
			return -1;
		if (indexStr.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Not a number\n";
			continue;
		}
		try {
			index = std::stoi(indexStr);
		}
		catch (std :: invalid_argument &ex) {
			std :: cout << "Not a number\n";
			continue;
		}
		catch (std :: out_of_range &ex){
			std :: cout << "Outside of range\n";
			continue;
		}
		if (index > 0 && index <= this->_phonebookSize)
			return index;
		else
			std :: cout << "Outside of range\n";
	}
}

void	Phonebook::search() {

	int index;

	if (this->_phonebookSize == 0){
		std::cout << "Nothing to display\n";
		return;
	}
	_displayAllContacts();
	index = _askForIndex();
	if (index  == -1)
		return;
	this->_contacts[index - 1].displayAllInfo();
}

static void moveContacts(Contact *_contacts) {

	for (int i = 1; i < 8; i++) {
		_contacts[i - 1] = _contacts[i];
	}

}

void	Phonebook::addContact() {

	if (this->_phonebookSize == 8)
		moveContacts(this->_contacts);

	if (this->_phonebookSize < 8)
		this->_phonebookSize++;

	do
		std :: cout << "Please input a first name: ";
	while (!this->_contacts[this->_phonebookSize - 1].setFirstName());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a last name: ";
	while (!this->_contacts[this->_phonebookSize - 1].setLastName());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a nickname: ";
	while (!this->_contacts[this->_phonebookSize - 1].setNickName());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a phone number: ";
	while (!this->_contacts[this->_phonebookSize - 1].setPhoneNumber());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a darkest secret: ";
	while (!this->_contacts[this->_phonebookSize - 1].setDarkestSecret());

}
