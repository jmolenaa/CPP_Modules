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

Phonebook::Phonebook() : _phonebookSize(0), _currentIndex(0) {}

Phonebook::~Phonebook() = default;

void	Phonebook::printStuff() const {
	std :: cout << "size: " << this->_phonebookSize << "\ncurrent_index: " << this->_currentIndex << std::endl;
}

void	Phonebook::addContact() {

	do
		std :: cout << "Please input a first name: ";
	while (!this->_contacts[this->_currentIndex].setFirstName());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a last name: ";
	while (!this->_contacts[this->_currentIndex].setLastName());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a nickname: ";
	while (!this->_contacts[this->_currentIndex].setNickName());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a phone number: ";
	while (!this->_contacts[this->_currentIndex].setPhoneNumber());

	if (std::cin.eof())
		return;
	do
		std :: cout << "Please input a darkest secret: ";
	while (!this->_contacts[this->_currentIndex].setDarkestSecret());

	this->_currentIndex = (this->_currentIndex + 1) % 8;
	if (this->_phonebookSize < 8)
		this->_phonebookSize++;
}
