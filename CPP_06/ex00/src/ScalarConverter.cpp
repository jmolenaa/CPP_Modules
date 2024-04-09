/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 09:11:27 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/08 09:11:27 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 8-4-24.
//

#include "ScalarConverter.hpp"
#include <iostream>
#include "defines.h"
#include <cmath>

typedef void	(*printFunction)(std::string const& inputStr);

static void	printChar(std::string const& inputStr) {
	char	c = inputStr[1];

	if (!isprint(c)) {
		std::cout << "char: Non displayable\n";
	}
	else {
		std::cout << "char: " << inputStr << "\n";
	}
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

static void	printSingleChar(char num) {
	if (isprint(num)) {
		std::cout << "char: '" << static_cast<char>(num) << "'\n";
	}
	else if (isascii(num)) {
		std::cout << "char: Non displayable\n";
	}
	else {
		std::cout << "char: impossible\n";
	}
}

static void	printInt(std::string const& inputStr) {

	int num = std::stoi(inputStr);

	printSingleChar(static_cast<char>(num));
	std::cout << "int: " << num << "\n";
	std::cout << "float: " << static_cast<float>(num) << ".0f\n";
	std::cout << "double: " << static_cast<double>(num) << ".0\n";
}

static void	printFloat(std::string const& inputStr) {

	float	num = std::stof(inputStr);
	bool	hasNoDecimal = (std::floor(num) - num == 0);
	if (hasNoDecimal) {
		printSingleChar(static_cast<char>(num));
		std::cout << "int: " << static_cast<int>(num) << "\n";
		std::cout << "float: " << num << ".0f\n";
		std::cout << "double: " << static_cast<double>(num) << ".0\n";
	}
	else {
		std::cout << "char: impossible\n";
		std::cout << "int: " << static_cast<int>(num) << "\n";
		std::cout << "float: " << num << "f\n";
		std::cout << "double: " << static_cast<double>(num) << "\n";
	}
}

static void	printDouble(std::string const& inputStr) {
	(void)inputStr;
	std::cout << "double\n";

}

static void	printPseudo(std::string const& inputStr) {
	(void)inputStr;
	std::cout << "pseudo\n";

}

static void	isChar(std::string const& inputStr, printFunction* func) {
	if (*func != nullptr) {
		return ;
	}
	if (inputStr.length() == 3 && inputStr[0] == '\'' && inputStr[2] == '\'') {
		*func = printChar;
	}
}

static void	isInt(std::string const& inputStr, printFunction* func) {
	if (*func != nullptr) {
		return ;
	}

	size_t	start = 0;
	if (inputStr[0] == '-' || inputStr[0] == '+') {
		++start;
	}
	if (inputStr.find_first_not_of("0123456789", start) == std::string::npos) {
		*func = printInt;
	}
}

static void	isFloatOrDouble(std::string const& inputStr, printFunction* func) {
	if (*func != nullptr) {
		return ;
	}

	size_t	start = 0;
	if (inputStr[0] == '-' || inputStr[0] == '+') {
		++start;
	}

	size_t	nonDigitPos = inputStr.find_first_not_of("0123456789", start);

	if (inputStr[nonDigitPos] != '.' || nonDigitPos == start || !std::isdigit(inputStr[nonDigitPos + 1])) {
		return ;
	}

	nonDigitPos = inputStr.find_first_not_of("0123456789", nonDigitPos + 1);

	if (nonDigitPos == std::string::npos) {
		*func = printDouble;
	}
	else if (inputStr[nonDigitPos] == 'f' && nonDigitPos == inputStr.length() - 1) {
		*func = printFloat;
	}
}

static void	isPseudo(std::string const& inputStr, printFunction* func) {
	if (*func != nullptr) {
		return ;
	}
	if (inputStr == "inf" || inputStr == "inff" || inputStr == "+inf" || inputStr == "+inff" ||
		inputStr == "-inf" || inputStr == "-inff" || inputStr == "nan" || inputStr == "nanf") {
		*func = printPseudo;
	}
}

static bool	isEdgeString(std::string const& inputStr) {
	if (inputStr.empty() ||
		(inputStr.length() == 1 && (inputStr[0] == '-' || inputStr[0] == '+'))) {
		return true;
	}
	return false;
}

void ScalarConverter::convert(std::string const &inputStr) {

	printFunction	func = nullptr;

	if (!isEdgeString(inputStr)) {
		isChar(inputStr, &func);
		isInt(inputStr, &func);
		isFloatOrDouble(inputStr, &func);
		isPseudo(inputStr, &func);
	}
	if (func == nullptr) {
		std::cerr << RED << "String literal couldn't be identified\n" << RESET;
		return ;
	}
	try {
		func(inputStr);
	}
	catch (std::out_of_range& e) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}
