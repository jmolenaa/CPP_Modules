/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 09:11:35 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/08 09:11:35 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cerr << "Input only 2 arguments\n";
		return 1;
	}
	std::cout << "\nTesting with string: \"" << argv[1] << "\"\n";
	ScalarConverter::convert(argv[1]);

}
