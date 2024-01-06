/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:11:40 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 13:11:41 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB{

private:
	std :: string const	_name;
	Weapon*				_weapon;

public:
	HumanB(const std :: string& name);
	~HumanB();
	void	setWeapon(Weapon& weapon);
	void	attack() const;

};

#endif
