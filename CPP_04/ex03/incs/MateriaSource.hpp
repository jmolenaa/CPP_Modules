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

private:
	AMateria*	_learntMaterias[4] {nullptr};
	size_t		_alreadyKnown = 0;

public:
	// OCF stuff
	MateriaSource() = default;
	MateriaSource(MateriaSource const& src);
	MateriaSource&	operator=(MateriaSource const& rhs);
	~MateriaSource() override;

	void learnMateria(AMateria *newMateria) override;
	AMateria * createMateria(const std::string &type) override;
};


#endif //CPP04_MATERIASOURCE_HPP
