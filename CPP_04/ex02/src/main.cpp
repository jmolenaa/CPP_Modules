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
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	testsExOne() {
	{
		std::cout << "Subject tests\n\n";

		std::cout << "Constructors\n";
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();

		std::cout << "\nTypes\n";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << "\nMaking sounds\n";
		i->makeSound(); //will output the cat sound!
		j->makeSound();

		std::cout << "\nDestructing\n";
		delete i;
		delete j;
	}
	{
		std::cout << "\nSome of my own\n\n";
		std::cout << "Wrong animal stuff\n\n";

		std::cout << "Constructors\n";
		WrongAnimal const*	a = new WrongAnimal();
		WrongAnimal const*	b = new WrongCat();
		WrongCat const*		c = new WrongCat();

		std::cout << "\nMaking sounds\n";
		a->makeSound();
		b->makeSound();
		c->makeSound();

		std::cout << "\nDestructing\n";
		delete c;
		delete b;
		delete a;
	}
}

void	testExTwo() {
	{
		std::cout << "Subject tests\n\n";

		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();
		std::cout << "\n";
		delete j;
		delete i;
	}
	{
		std::cout << "\nSome of my own\n\n";

		std::cout << "Animal array\n\n";
		AAnimal	*array[10];
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
}


int	main() {
	testsExOne();
	testExTwo();

//	AAnimal	a;
//	AAnimal*	b = new AAnimal();

	return 0;
}
