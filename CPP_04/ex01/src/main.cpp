/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:07:22 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:07:22 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	{
		std::cout << "Subject tests\n\n";

		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << "\n";
		delete j;
		delete i;
	}
	{
		std::cout << "\nSome of my own\n\n";

		std::cout << "Animal array\n\n";
		Animal	*array[10];
		std::cout << "Constructing animals\n";
		for (int i = 0; i < 10; ++i) {
			if (i > 4) {
				array[i] = new Dog();
			}
			else {
				array[i] = new Cat();
			}
		}
		std::cout << "\nCreating a ruckus\n";
		for (int i = 0; i < 10; ++i) {
			array[i]->makeSound();
		}
		std::cout << "\nDeleting the menagerie\n";
		for (int i = 0; i < 10; ++i) {
			delete array[i];
		}
	}
	{
		std::cout << "\nWrong animals to show the leaks and destructors being messy, commented out so you don't complain about leaks you jokster\n\n";
		/*
		WrongAnimal	*array[10];
		std::cout << "Constructing animals\n";
		for (int i = 0; i < 10; ++i) {
				array[i] = new WrongCat();
		}
		std::cout << "\nCreating a ruckus\n";
		for (int i = 0; i < 10; ++i) {
			array[i]->makeSound();
		}
		std::cout << "\nDeleting the menagerie\n";
		for (int i = 0; i < 10; ++i) {
			delete array[i];
		}
		*/

	}
	return 0;
}
