/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:24:29 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/04 11:24:31 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie {

private:
	std :: string	_name;

public:
	void	announce() const;
	void	setName(std :: string name);

	Zombie(std :: string name);
	Zombie();
	~Zombie();
};

#endif
