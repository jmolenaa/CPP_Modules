/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:10 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:10 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#ifndef CPP04_CURE_HPP
#define CPP04_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

public:
	// OCF stuff
	Cure();
	Cure(Cure const& src);
	Cure&	operator=(Cure const& rhs);
	~Cure() override = default;

	AMateria * clone() const override;
	void use(ICharacter &target) override;

};


#endif //CPP04_CURE_HPP
