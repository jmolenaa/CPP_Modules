/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:15:58 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 18:15:59 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool	handleErrors(int argc, char *argv[]){
	if (argc != 4){
		std::cerr	<< "Wrong number of arguments\n"
					<< "Usage: ./loser [filename] [string to replace] [string to replace with]";
		return false;
	}
	if (*argv[2] == '\0'){
		std::cerr << "String to replace shouldn't be empty\n";
		return false;
	}
	return true;
}

bool	openFiles(std::ifstream& file, std::ofstream& output_file, char* argv) {

	std::string	fileName = argv;
	file.open(fileName);
	if (file.is_open() == false) {
		std::cerr << "Input file couldn't be opened\n";
		return false;
	}
	fileName = fileName + ".replace";
	output_file.open(fileName);
	if (output_file.is_open() == false){
		std::cerr << "Output file couldn't be opened\n";
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	std::ifstream file;
	std::ofstream output_file;

	if (handleErrors(argc, argv) == false){
		return 1;
	}
	if (openFiles(file, output_file, argv[1]) == false){
		return 1;
	}

	std::cout<<file.is_open();
}
