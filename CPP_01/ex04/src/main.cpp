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

bool	openFiles(std::ifstream& file, std::ofstream& output_file, const char* argv) {

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

void	replaceStringsAndWriteToFile(std::ifstream& file, std::ofstream& output_file, std::string s1, std::string s2){
	std::string	line;
	size_t		pos;
	size_t		start;

	while (std::getline(file, line)){

		start = 0;
		while (line.find(s1, start) != std::string::npos){
			pos = line.find(s1, start);
			output_file << line.substr(start, pos - start) << s2;
			start = pos + s1.length();
		}
		output_file << line.substr(start);

		if (!file.eof()) {
			output_file << "\n";
		}
	}
	output_file.flush();
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

	replaceStringsAndWriteToFile(file, output_file, argv[2], argv[3]);
}
