/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:52:17 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:52:17 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "defines.h"

// TODO

void	testingMateria() {
	Ice			a;
	Cure		b;
	Character	c;

	std::cout << BLUE << "Testing the Ice and Cure class\n\n" << RESET;
	std::cout << a.getType() << "\n";
	std::cout << b.getType() << "\n";
	a.use(c);
	b.use(c);

	AMateria*	clone;
	clone = a.clone();
	std::cout << clone->getType() << "\n";
	clone->use(c);
	delete clone;
	clone = b.clone();
	std::cout << clone->getType() << "\n";
	clone->use(c);
	delete clone;

	Ice*	d = new Ice(a);
	Cure*	e = new Cure(b);

	std::cout << d->getType() << "\n";
	std::cout << e->getType() << "\n";
	d->use(c);
	e->use(c);
	*d = a;
	*e = b;
	std::cout << d->getType() << "\n";
	std::cout << e->getType() << "\n";
	d->use(c);
	e->use(c);
	delete d;
	delete e;
}

void	testingCharacter() {
	Character a;
	Character b("Luigi");
	Character c(b);

	c = a;
	std::cout << a.getName() << "\n";
	std::cout << b.getName() << "\n";
	std::cout << c.getName() << "\n";
	Ice *	d = new Ice();
	Cure*	e = new Cure();

	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.equip(e);
	delete e;
	a.use(0, b);
	a.use(1, b);
	a.use(2, b);
	a.use(3, b);

	std::cout << BLUE << "\nTesting indexes of slots that haven't been equipped and out of range\n" << RESET;
	b.use(0, a);
	b.use(1, a);
	b.use(2, a);
	b.use(3, a);
	b.use(4, a);
	b.use(-1, a);

	std::cout << BLUE << "\nTesting adding a fifth weapon\n" << RESET;
	a.equip(d);
	std::cout << BLUE << "\nRemoving a weapon, then trying to use it, then trying to add a new one\n" << RESET;
	a.unequip(0);
	a.use(3, b);
	a.equip(d);
	a.use(3, b);

	std::cout << BLUE << "\nUnequipping everything, trying to use all slots\n" << RESET;
	a.unequip(0);
	a.unequip(0);
	a.unequip(0);
	a.unequip(0);
	a.use(0, b);
	a.use(1, b);
	a.use(2, b);
	a.use(3, b);

	std::cout << BLUE << "\nTrying to add a nullptr as a materia";
	a.equip(nullptr);

	std::cout << BLUE << "\nGoing nuts with equipping, unequipping and using the materias to see if it breaks and everything is freed correctly\n" << RESET;
	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.unequip(2);
	a.unequip(2);
	a.use(1, b);
	a.use(2, b);
	a.unequip(-1);
	a.unequip(3);
	a.unequip(5);
	a.equip(d);
	a.use(1, b);
	a.use(0, b);
	a.equip(d);
	a.equip(d);
	a.unequip(0);
	a.unequip(0);
	a.unequip(0);
	a.unequip(0);
	a.unequip(0);
	a.equip(d);
	a.equip(d);
	a.equip(d);
	a.unequip(0);
	a.use(4, b);
	a.use(3, b);
	a.use(2, b);
	a.use(1, b);

	std::cout << BLUE << "\nTesting deep copies\n" << RESET;
	{
		Character*	g = new Character(a);

		g->use(0, a);
		g->use(2, a);
		g->unequip(0);
		*g = a;
		*g = b;
		*g = a;
		g->use(1, a);
		g->equip(d);
		delete g;
	}
	a.use(0, b);
	delete d;
}

void	testingMateriaSource() {
	MateriaSource	a;
	MateriaSource	b(a);
	MateriaSource*	c = new MateriaSource(a);
	*c = a;

	Ice		d;

	Character	cha("Luigi");
	std::cout << BLUE << "\nTrying to create materia from a class that hasn't learnt anything\n" << RESET;
	a.createMateria("ice");
	a.createMateria("cure");
	a.createMateria("asdsadasd");
	a.learnMateria(&d);
	{
		std::cout << BLUE << "\nTrying to create materia when only one was learnt\n" << RESET;
		AMateria *g = a.createMateria("ice");
		AMateria *h = a.createMateria("cure");

		AMateria *j = a.createMateria("");
		AMateria *k = a.createMateria("sadsagdsagidiusadsagdiusa");
		std::cout << h << " " << j << " " << k << "\n";
		g->use(cha);
		delete g;
	}
	std::cout << BLUE << "\nGiving materia to a character and checking for segfaults and leaks\n" << RESET;
	AMateria*	mat = a.createMateria("ice");
	cha.equip(mat);
	cha.equip(mat);
	cha.use(0, cha);
	cha.use(3, cha);
	cha.use(1, cha);

	std::cout << BLUE << "\nFilling up the MateriaSource\n" << RESET;
	Cure	e;
	Ice*	f = new Ice(d);
	a.learnMateria(&e);
	a.learnMateria(f);
	a.learnMateria(f);
	a.learnMateria(f);
	delete mat;
	delete c;
	delete f;

}

int	main() {

//	testingMateria();
//	testingCharacter();
//	testingMateriaSource();

	return (0);
}
