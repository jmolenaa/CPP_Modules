/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 11:59:27 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/25 11:59:27 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 25-7-24.
//

#include "BitcoinExchange.hpp"
#include "defines.h"
#include <sstream>

BitcoinExchange::BitcoinExchange() : earliestDate(), oldestDate() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : earliestDate(src.getEarliestDate()), oldestDate(src.getOldestDate()) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		this->earliestDate = rhs.getEarliestDate();
		this->oldestDate = rhs.getOldestDate();
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &databaseName) : earliestDate(), oldestDate() {
	if (databaseName.length() < 4 || databaseName.substr(databaseName.length() - 4, 4) != ".csv") {
		throw BitcoinExchangeException("Wrong file extension: " + databaseName + ", file should end with '.csv'");
	}

	std::ifstream	databaseFile(databaseName);
	if (databaseFile.fail()) {
		throw BitcoinExchangeException("Failed to open configuration file: " + databaseName);
	}
	parseDatabase(databaseFile);
	databaseFile.close();
}

void BitcoinExchange::checkOldestEarliestValues(const Date &newDate) {
	if (this->database.size() == 1) {
		earliestDate = newDate;
		oldestDate = newDate;
	}
	else if (newDate < earliestDate) {
		earliestDate = newDate;
	}
	else if (newDate > oldestDate) {
		oldestDate = newDate;
	}
}

void BitcoinExchange::parseDatabase(std::ifstream &databaseFile) {
	std::string	line;
	size_t		i = 1;

	std::getline(databaseFile, line); // skip first line

	while (std::getline(databaseFile, line)) {
		++i;
		std::stringstream	lineStream(line);
		std::string			date;
		float				value;

		std::getline(lineStream, date, ',');
		lineStream >> value;
		if (lineStream.fail() || !lineStream.eof()) {
			std::cout << REDSTRING("Skipping line "  + std::to_string(i) + ", due to wrong formatting of line\n");
			continue ;
		}

		try {
			Date	newDate(date);
			this->database[newDate] = value;
			checkOldestEarliestValues(newDate);
		}
		catch (Date::InvalidDateFormatException& e) {
			std::cout << REDSTRING("Skipping line "  + std::to_string(i) + ", due to wrong formatting of date\n");
		}
	}
}

float BitcoinExchange::convertSingleValue(const std::string &date, const float &value) {
	(void)date;
	(void)value;
	try {
		Date	dateToEvaluate(date);

		while (dateToEvaluate > this->earliestDate) {
			if (this->database.count(dateToEvaluate) != 0) {
				return (value * this->database[dateToEvaluate]);
			}
			--dateToEvaluate;
		}
		std::cout << RED << "Error: date earlier than any in the database\n" << RESET;
	}
	catch (Date::InvalidDateFormatException& e) {
		std::cout << RED << "Error: " << e.what() << ": " << date << "\n" << RESET;
	}
	return -1;
}

const Date &BitcoinExchange::getEarliestDate() const {
	return this->earliestDate;
}

const Date &BitcoinExchange::getOldestDate() const {
	return this->oldestDate;
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const std::string &reason) {
	this->_reason = reason + "\n";
}

char const *BitcoinExchange::BitcoinExchangeException::what() const noexcept {
	return (this->_reason.c_str());
}
