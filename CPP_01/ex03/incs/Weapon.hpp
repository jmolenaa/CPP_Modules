/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:11:48 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 13:12:06 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon{

private:
	std :: string	_type;

public:
	Weapon(std :: string type);
	~Weapon();
	const std :: string&	getType() const;
	void					setType(std :: string newType);

};

#endif
