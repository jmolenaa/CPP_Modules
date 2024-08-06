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

//BitcoinExchange::BitcoinExchange() {
//
//}
//
//BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
//	(void)src;
//
//}

//BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
//	if (this != &rhs) {
//
//	}
//	return *this;
//}

BitcoinExchange::BitcoinExchange(const std::string &databaseName) {
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
			this->database[Date(date)] = value;
		}
		catch (Date::InvalidDateFormatException& e) {
			std::cout << REDSTRING("Skipping line "  + std::to_string(i) + ", due to wrong formatting of date\n");
		}
	}
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const std::string &reason) {
	this->_reason = reason + "\n";
}

char const *BitcoinExchange::BitcoinExchangeException::what() const noexcept {
	return (this->_reason.c_str());
}
