/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:19 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:19 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
	std::string	_type;
	void		setType(std::string type);

public:
	// OCF stuff
	AMateria() = default;
	AMateria(AMateria const& src) = default;
	AMateria&	operator=(AMateria const& rhs);
	virtual ~AMateria() = default;

	explicit AMateria(std::string const& type);

	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

};


#endif //CPP04_AMATERIA_HPP
