/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 11:51:51 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/10 11:51:51 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

// TODO
// Read about what the reinterpret cast is used for and what serializing is for
int main() {

	Data	*someData = new Data();

	someData->i = 42;
	std::cout << "Address of Data class: " << someData << "\n";
	std::cout << "Value of Data class: " << someData->i << "\n";
	std::cout << "\n";

	uintptr_t	tempPtr = Serializer::serialize(someData);

	std::cout << "Address stored in temporary pointer: " << tempPtr << "\n";
//	std::cout << "Address stored in temporary pointer in hex: " << std::hex << tempPtr <<  "\n";
	std::cout << "\n";

	std::cout << "Address returned from deserialize: " << Serializer::deserialize(tempPtr) << "\n";
	std::cout << "Value from deserialize: " << Serializer::deserialize(tempPtr)->i << "\n";
	std::cout << "\n";

	std::cout << "Changing value in Data class and then checking the address and the value again\n";
	someData->i = 123213213;
	std::cout << "Address returned from deserialize: " << Serializer::deserialize(tempPtr) << "\n";
	std::cout << "Value from deserialize: " << Serializer::deserialize(tempPtr)->i << "\n";


	delete someData;

}
