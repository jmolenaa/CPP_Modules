/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:19:22 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/04 17:19:23 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std :: string name){
	Zombie*	zombies;

	if (N < 0)
		return nullptr;
	try {
		zombies = new Zombie[N];
	}
	catch (std :: bad_alloc &ex) {
		std :: cerr << "Memory allocation failure\n";
	}
	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}
	return (zombies);
}
