/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: janmolenaar <janmolenaar@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 12:07:25 by janmolenaar   #+#    #+#                 */
/*   Updated: 2024/08/28 12:07:25 by janmolenaar   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Jan Molenaar on 28/08/2024.
//

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include "defines.h"

int RPN::popStack() {
	int number = this->operands.top();
	this->operands.pop();
	return number;
}

int RPN::handleOperation(char operato) {
	if (this->operands.size() < 2) {
		std::cout << REDSTRING("Not enough operands to execute operation\n");
		return -1;
	}
	int	operand2 = this->popStack();
	int	operand1 = this->popStack();
	int	newNumber;
	switch (operato) {
		case '+':
			newNumber = operand1 + operand2;
			break;
		case '-':
			newNumber = operand1 - operand2;
			break;
		case '*':
			newNumber = operand1 * operand2;
			break;
		case '/':
			if (operand2 == 0) {
				std::cout << REDSTRING("Division by 0\n");
				return -1;
			}
			newNumber = operand1 / operand2;
			break;
		default:
			std::cout << REDSTRING("Invalid operator\n");
			return -1;
	}
	this->operands.push(newNumber);
//	std::cout << newNumber << "\n";
	return 1;
}

void RPN::processExpression(std::string const& expressionString) {
	std::stringstream	expression(expressionString);
	std::string			token;

	while (!expression.eof()) {
		expression >> token;
		if (token.size() > 1) {
			std::cout << REDSTRING("Invalid token: '" + token + "' - contains too many characters\n");
			return ;
		}
		else if (isdigit(token[0])) {
			this->operands.push(std::stoi(token));
		}
		else if (handleOperation(token[0]) == -1) {
			return;
		}
//		std::cout << token << "\n";
	}
	if (this->operands.size() != 1) {
		std::cout << REDSTRING("Wrong ratio of operands to operators, there should be one more operand than operators\n");
	}
	else {
		std::cout << this->operands.top() << "\n";
	}
}
