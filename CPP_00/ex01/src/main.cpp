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

bool	checkEndOfFile(){
	if (std::cin.eof())
	{
		std :: cout << "\nNice try buddy\n";
		return true;
	}
	return false;
}

int	main()
{
	std :: string	input;
	Phonebook		phonebook;

//	phonebook.printStuff();
	while (std :: getline(std::cin, input)) {
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			std::cout << "Searching\n";
		else if (input == "EXIT")
			break ;
		else
			std :: cout << input << "\n";
	}
	checkEndOfFile();
}
