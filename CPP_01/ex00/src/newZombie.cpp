/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:28:18 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/04 11:28:21 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std :: string name){

	Zombie	*heapZombie;

	try {
		heapZombie = new Zombie(name);
	}
	catch (std :: bad_alloc &ex){
		std :: cerr << "Memory allocation failure\n";
	}
	return (heapZombie);

}

