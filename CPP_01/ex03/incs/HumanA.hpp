/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:11:27 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 13:11:33 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA{

private:
	std :: string const	_name;
	const Weapon&		_weapon;

public:
	HumanA(const std :: string& name, Weapon& weapon);
	~HumanA();
	void	attack() const;

};


#endif
