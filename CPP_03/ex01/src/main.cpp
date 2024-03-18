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

#include "ScavTrap.hpp"
#include <iostream>

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

int	main(){
	ScavTrap	a;

	a.lol();
}