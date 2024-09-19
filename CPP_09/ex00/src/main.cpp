/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 11:59:58 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/25 11:59:58 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "BitcoinExchange.hpp"
#include <sstream>

bool	isValidFormat(std::string const& delimiter, float value, std::stringstream& lineStream, std::string const& line) {
	if (lineStream.fail() || !lineStream.eof()) {
		std::cout << REDSTRING("Error: bad format: " + line + "\n");
	}
	else if (delimiter != "|") {
		std::cout << REDSTRING("Error: bad format: " + line + "\n");
	}
	else if (value < 0) {
		std::cout << REDSTRING("Error: not a positive number: " + line + "\n");
	}
	else if (value > 1000) {
		std::cout << REDSTRING("Error: number too large: " + line + "\n");
	}
	else {
		return true;
	}
	return false;
}

void	convertValues(std::ifstream& databaseToEvaluate, BitcoinExchange& priceDatabase) {
	std::string	line;

	std::getline(databaseToEvaluate, line);
	while (std::getline(databaseToEvaluate, line)) {
		std::stringstream	lineStream(line);
		std::string			date;
		std::string			delimiter;
		float				value;

		lineStream >> date >> delimiter >> value;
		if (isValidFormat(delimiter, value, lineStream, line)) {
			float walletValue = priceDatabase.convertSingleValue(date, value);
			if (walletValue >= 0) {
				std::cout << GREEN << date << " => " << value << " = " << walletValue << "\n" << RESET;
			}
		}
	}
}

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << REDSTRING("Program requires 2 arguments\n");
		return (1);
	}

	std::ifstream	databaseToEvaluate(argv[1]);
	if (databaseToEvaluate.fail()) {
		std::cout << REDSTRING("Failed to open second database\n");
		return (1);
	}

	try {
		BitcoinExchange	priceDatabase("data.csv");
		convertValues(databaseToEvaluate, priceDatabase);
	}
	catch (BitcoinExchange::BitcoinExchangeException &e) {
		std::cout << e.what();
		databaseToEvaluate.close();
		return (1);
	}

	databaseToEvaluate.close();
	return (0);
}