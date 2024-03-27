/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:02 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:02 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

	//TODO
	// Also add the inventory stuff for 4 materias
public:
	// OCF stuff
	MateriaSource();
	MateriaSource(MateriaSource const& src);
	MateriaSource&	operator=(MateriaSource const& rhs);
	~MateriaSource();

	void learnMateria(AMateria *) override;
	AMateria * createMateria(const std::string &type) override;
};


#endif //CPP04_MATERIASOURCE_HPP
