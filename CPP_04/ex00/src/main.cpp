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
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
//		delete meta;
//		delete j;
//		delete i;
	}
	{
		std::cout << "\nSome of my own\n\n";
		std::cout << "Wrong animal stuff\n\n";
		WrongAnimal const*	a = new WrongAnimal();
		WrongAnimal const*	b = new WrongCat();
		Cat const*			c = new Cat();
		a->makeSound();
		b->makeSound();
		delete c;
	}

	return 0;
}
