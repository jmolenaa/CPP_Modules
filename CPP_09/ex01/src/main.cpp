/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: janmolenaar <janmolenaar@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 12:07:38 by janmolenaar   #+#    #+#                 */
/*   Updated: 2024/08/28 12:07:38 by janmolenaar   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "defines.h"
#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << REDSTRING("Program requires 2 arguments\n");
		return (1);
	}

	if (argv[1][0] == '\0') {
		std::cout << REDSTRING("Empty string joker\n");
		return (1);
	}
	RPN	calculator;
	calculator.processExpression(argv[1]);
	return (0);
}
