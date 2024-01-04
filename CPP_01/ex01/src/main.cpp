/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:19:09 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/04 17:19:11 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std :: string name);

int	main(){

	Zombie*	zombies;
	int		N = -1;

	zombies = zombieHorde(N, "NPC");
	std :: cout << zombies << "\n";
	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
}