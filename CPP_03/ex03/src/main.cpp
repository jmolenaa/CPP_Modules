/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:37:35 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 10:37:35 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

void	testsExZero() {
	{
		std::cout << "\nUsing up all energy\n\n";
		ClapTrap	a;

		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.attack("Chad");
		a.beRepaired(10);
		a.printClaptrap();
	}
	{
		std::cout << "\nLosing all hp\n\n";
		ClapTrap	a;

		a.takeDamage(5);
		a.takeDamage(10);
		a.attack("Chad");
		a.beRepaired(10);
		a.printClaptrap();
	}
	{
		std::cout << "\nTaking damage and repairing it\n\n";
		ClapTrap a;

		a.printClaptrap();
		a.takeDamage(5);
		a.printClaptrap();
		a.beRepaired(1);
		a.beRepaired(1);
		a.beRepaired(1);
		a.printClaptrap();
		a.beRepaired(5);
		a.printClaptrap();
		a.takeDamage(20);
		a.printClaptrap();
	}
}

void	testExOne(){
	{
		std::cout << GREEN << "Showing proper construction chaining for all constructors, different messages and stats\n\n" << RESET;
		std::cout << CYAN << "Default constructor\n" << RESET;
		ScavTrap	a;
		std::cout << "\n";
		a.printClaptrap();
	}
	{
		std::cout << CYAN << "\nParameterized constructor\n" << RESET;
		ScavTrap	a("Evaluator");
		std::cout << "\n";
		a.printClaptrap();
	}
	{
		std::cout << CYAN << "\nCopy constructor\n" << RESET;
		ScavTrap	a;
		std::cout << "\n";
		a.takeDamage(20);
		ScavTrap	b(a);
		std::cout << "\n";
		b.printClaptrap();
	}
	{
		std::cout << CYAN << "\nAssignment operator\n" << RESET;
		ScavTrap	a;
		std::cout << "\n";
		ScavTrap	b("Scooter");
		std::cout << "\n";
		a.takeDamage(50);
		b = a;
		b.printClaptrap();
	}
	{
		std::cout << GREEN << "\nShowing different messages for attacking\n\n" << RESET;
		ClapTrap	a;
		std::cout << "\n";
		ScavTrap	b;
		std::cout << "\n";
		a.attack("Lillith");
		b.attack("Roland");

		std::cout << GREEN << "\nGuard gate\n" << RESET;
		b.guardGate();
		b.takeDamage(100);
		b.guardGate();
	}
}

void	testExTwo() {
	{
		std::cout << GREEN << "Showing proper construction chaining for all constructors, different messages and stats\n\n" << RESET;
		std::cout << CYAN << "Default constructor\n" << RESET;
		FragTrap	a;
		std::cout << "\n";
		a.printClaptrap();
	}
	{
		std::cout << CYAN << "\nParameterized constructor\n" << RESET;
		FragTrap	a("Evaluator");
		std::cout << "\n";
		a.printClaptrap();
	}
	{
		std::cout << CYAN << "\nCopy constructor\n" << RESET;
		FragTrap	a;
		std::cout << "\n";
		a.takeDamage(20);
		FragTrap	b(a);
		std::cout << "\n";
		b.printClaptrap();
	}
	{
		std::cout << CYAN << "\nAssignment operator\n" << RESET;
		FragTrap	a;
		std::cout << "\n";
		FragTrap	b("Scooter");
		std::cout << "\n";
		a.takeDamage(50);
		b = a;
		b.printClaptrap();
	}
	{
		std::cout << GREEN << "\nShowing different messages for attacking\n\n" << RESET;
		ClapTrap	a;
		std::cout << "\n";
		FragTrap	b;
		std::cout << "\n";
		a.attack("Lillith");
		b.attack("Roland");

		std::cout << GREEN << "\nHigh fives\n" << RESET;
		b.highFivesGuys();
		b.takeDamage(100);
		b.highFivesGuys();
	}

}

void	testExThree() {
	{
		std::cout << GREEN << "Showing proper construction chaining for all constructors, different messages and stats\n\n" << RESET;
		std::cout << CYAN << "Default constructor\n" << RESET;
		DiamondTrap	a;
		std::cout << "\n";
		a.printClaptrap();
		a.whoAmI();
		std::cout << "\n";
	}
	{
		std::cout << CYAN << "\nParameterized constructor\n" << RESET;
		DiamondTrap	a("Evaluator");
		std::cout << "\n";
		a.printClaptrap();
		a.whoAmI();
		std::cout << "\n";
	}
	{
		std::cout << CYAN << "\nCopy constructor\n" << RESET;
		DiamondTrap	a("Chad");
		std::cout << "\n";
		a.takeDamage(20);
		DiamondTrap	b(a);
		std::cout << "\n";
		b.printClaptrap();
		a.whoAmI();
		std::cout << "\n";
	}
	{
		std::cout << CYAN << "\nAssignment operator\n" << RESET;
		DiamondTrap	a;
		std::cout << "\n";
		DiamondTrap	b("Scooter");
		std::cout << "\n";
		a.takeDamage(50);
		b = a;
		b.printClaptrap();
		a.whoAmI();
		std::cout << "\n";
	}
	{
		std::cout << GREEN << "\nShowing different messages for attacking\n\n" << RESET;
		ClapTrap	a;
		std::cout << "\n";
		DiamondTrap	b;
		std::cout << "\n";
		ScavTrap	c;
		std::cout << "\n";
		a.attack("Lillith");
		b.attack("Roland");
		c.attack("Brick");

		std::cout << GREEN << "\nTaking names\n" << RESET;
		b.whoAmI();
		b.takeDamage(100);
		b.whoAmI();
		std::cout << "\n";
	}
}

int	main(){
//	testsExZero();
//	testExOne();
//	testExTwo();
	testExThree();

}
