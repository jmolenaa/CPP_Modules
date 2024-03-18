/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:37:31 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/18 10:37:31 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
public:
	// Default
	ClapTrap();
	// Parameterized constr
	ClapTrap(std::string const& name);
	// Copy constr
	ClapTrap(ClapTrap const& src);
	// Assignment operator overload
	ClapTrap&	operator=(ClapTrap const& rhs);
	// Destructor
	~ClapTrap();

	void	attack(std::string const& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	printClaptrap();

protected:
	int							_hp;
	int							_ep;

private:
	std::string					_name;
	int							_ad;
	static unsigned int	const	_maxHP;


};


#endif
