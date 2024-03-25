/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 10:51:20 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/25 10:51:20 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:
	// Constructors, destructor and assignment operator
	DiamondTrap();
	DiamondTrap(DiamondTrap const& src);
	DiamondTrap(std::string const& name);
	DiamondTrap&	operator=(DiamondTrap const& rhs);
	~DiamondTrap();

	void	whoAmI();
	void	attack(std::string const& target);

private:
	std::string	_name;

};


#endif
