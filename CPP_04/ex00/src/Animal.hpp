/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:10:10 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:10:10 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP_04_ANIMAL_HPP
#define CPP_04_ANIMAL_HPP

#include <iostream>

class Animal {

public:
	// OCF stuff
	Animal();
	~Animal();
	Animal(Animal const& src);
	Animal&	operator=(Animal const&rhs);

	virtual void	makeSound() const;
	void			setType(std::string type);
	std::string		getType() const;

protected:
	std::string	_type;

};


#endif //CPP_04_ANIMAL_HPP
