/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ICharacter.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 16:25:25 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 16:25:25 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#ifndef CPP04_ICHARACTER_HPP
#define CPP04_ICHARACTER_HPP

#include "AMateria.hpp"

// TODO
// ask about if the interfaces need constructors at all, probalby?
class ICharacter {
public:
	virtual ~ICharacter();
	virtual std::string const& getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;

};


#endif //CPP04_ICHARACTER_HPP
