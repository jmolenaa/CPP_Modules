/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Floor.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 11:08:17 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/28 11:08:17 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 28-3-24.
//

#ifndef CPP04_FLOOR_HPP
#define CPP04_FLOOR_HPP

#include "AMateria.hpp"

class Floor {

private:
	// OCF stuff
	Floor();
	Floor(Floor const& src) = default;
	Floor&	operator=(Floor const& rhs) = default;

	AMateria**	floorClutter;
	size_t		currentCapacity = 10;
	size_t		currentItems = 0;

	void	increaseCapacity();

public:
	~Floor();
	static Floor&	getFloor();
	void			addToFloor(AMateria* toAdd);

};


#endif //CPP04_FLOOR_HPP
