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

bool	isValidFormat(std::string delimiter, float value, std::stringstream& lineStream, std::string const& line) {
	if (lineStream.fail() || !lineStream.eof()) {
		std::cout << REDSTRING("Error: bad format: " + line + "\n");
	}
	else if (delimiter != "|") {
		std::cout << REDSTRING("Error: bad format: " + line + "\n");
	}
	else if (value < 0) {
		std::cout << REDSTRING("Error: not a positive number\n" + line + "\n");
	}
	else if (value > 1000) {
		std::cout << REDSTRING("Error: number too large\n" + line + "\n");
	}
	else {
		return true;
	}
	return false;
}

void	convertValues(std::ifstream& databaseToEvaluate) {
	std::string	line;

	std::getline(databaseToEvaluate, line);
	while (std::getline(databaseToEvaluate, line)) {
		std::stringstream	lineStream(line);
		std::string			date;
		std::string			delimiter;
		float				value;
		lineStream >> date >> delimiter >> value;
		if (isValidFormat(delimiter, value, lineStream, line)) {
			std::cout << GREENSTRING("Success: " + line + "\n");
		}
	}
}

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << REDSTRING("Program requires 2 arguments\n");
		return (1);
	}
	try {
		BitcoinExchange("data.csv");
	}
	catch (BitcoinExchange::BitcoinExchangeException &e) {
		std::cout << e.what();
		return (1);
	}

	std::ifstream	databaseToEvaluate(argv[1]);
	if (databaseToEvaluate.fail()) {
		std::cout << REDSTRING("Failed to open second database\n");
		return (1);
	}
	convertValues(databaseToEvaluate);
	return (0);
}