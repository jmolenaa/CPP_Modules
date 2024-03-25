/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 09:25:38 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/25 09:25:38 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	// Constructors, destructor and assignment operator
	FragTrap();
	FragTrap(FragTrap const& src);
	FragTrap(std::string const& name);
	FragTrap&	operator=(FragTrap const& rhs);
	~FragTrap();

	void	highFivesGuys();
	void	attack(std::string const& target);

};

#endif
