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

int	main(){
	Harl	Harl;

	std::cout << "\nDebugging\n";
	Harl.complain("DEBUG");

	std::cout << "\nInfo\n";
	Harl.complain("INFO");

	std::cout << "\nWarning\n";
	Harl.complain("WARNING");

	std::cout << "\nErrors\n";
	Harl.complain("ERROR");

	std::cout << "\nRandom input\n";
	Harl.complain("LOL");
}
