/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:28:06 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/04 11:28:08 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	randomChump(std :: string name);
Zombie	*newZombie(std :: string name);

int	main(){
	Zombie	Billy("Billy");
	Zombie* Stacy;

	Billy.announce();

	std :: cout << "\n";
	randomChump("Chad");

	std :: cout << "\n";
	Stacy = newZombie("Stacy");
	Stacy->announce();
	delete Stacy;

	std :: cout << "\n";
	Stacy = newZombie("Tracy");
	delete Stacy;
	std :: cout << "\n";

}
