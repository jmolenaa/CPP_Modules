/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:13 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:13 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#ifndef CPP04_ICE_HPP
#define CPP04_ICE_HPP

#include "AMateria.hpp"

// TODO
// overriding destructors
class Ice : public AMateria {

public:
	// OCF stuff
	Ice();
	Ice(Ice const& src);
	Ice&	operator=(Ice const& rhs);
	~Ice() override = default;

	AMateria * clone() const override;
	void use(ICharacter &target) override;


};


#endif //CPP04_ICE_HPP
