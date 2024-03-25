/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 16:36:09 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 16:36:09 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

public:
	// Constructors, destructor and assignment operator
	ScavTrap();
	ScavTrap(ScavTrap const& src);
	ScavTrap(std::string const& name);
	ScavTrap&	operator=(ScavTrap const& rhs);
	~ScavTrap();

	void	guardGate();
	void	attack(std::string const& target);

protected:
	static int const	_initHp = 100;
	static int const	_initEp = 50;
	static int const	_initAd = 20;

};

#endif
