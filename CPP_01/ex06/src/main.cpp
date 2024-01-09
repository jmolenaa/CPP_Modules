/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:02:40 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/07 14:02:42 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

bool	checkForValidInput(std::string level) {
	if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR") {
		return true;
	}
	return false;
}

int	main(int argc, char *argv[]){
	if (argc != 2){
		std::cerr << "Incorrect amount of arguments\n";
		return 1;
	}
	if (checkForValidInput(argv[1]) == false){
		std::cerr << "Invalid complaint\n";
		return 1;
	}

	Harl	Harl;
	Harl.complain(argv[1]);
	return 0;
}
