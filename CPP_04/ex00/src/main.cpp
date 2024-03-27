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
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int	main() {
	{
		std::cout << "Subject tests\n\n";

		std::cout << "Constructors\n";
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << "\nTypes\n";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << "\nMaking sounds\n";
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << "\nDestructing\n";
		delete i;
		delete j;
		delete meta;
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

	return 0;
}
