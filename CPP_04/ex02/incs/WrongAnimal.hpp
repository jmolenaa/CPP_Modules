/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:10:02 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:10:02 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP04_WRONGANIMAL_HPP
#define CPP04_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

protected:
	std::string	_type;

public:
	// OCF stuff
	WrongAnimal();
	WrongAnimal(WrongAnimal const& src);
	WrongAnimal&	operator=(WrongAnimal const& rhs);
	~WrongAnimal();

	void		setType(std::string type);
	std::string	get_type() const;
	void		makeSound() const;
};


#endif //CPP04_WRONGANIMAL_HPP
