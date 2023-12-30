/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 13:27:34 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/12/29 13:27:35 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

int	main()
{
	std :: string	input;
	Phonebook		phonebook;

	while (std :: getline(std::cin, input)) {
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
		std :: cout << std::endl;
	}
	if (std::cin.eof())
		std :: cout << "\nNice try buddy\n";
}
