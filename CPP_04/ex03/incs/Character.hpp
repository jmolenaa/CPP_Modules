/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:55:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 15:55:05 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 27-3-24.
//

#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "ICharacter.hpp"

// TODO
// add inventory and named constructor
class Character : public ICharacter {

public:
	// OCF stuff
	Character();
	Character(Character const& src);
	Character&	operator=(Character const& rhs);
	~Character();

	const std::string & getName() const override;
	void equip(AMateria *m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter &target) override;

private:
	std::string	_name;
};


#endif //CPP04_CHARACTER_HPP
