/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:09:57 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:09:57 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP04_WRONGCAT_HPP
#define CPP04_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	// OCF stuff
	WrongCat();
	WrongCat(WrongCat const& src);
	WrongCat&	operator=(WrongCat const& rhs);
	~WrongCat();

	void	makeSound() const;
};


#endif //CPP04_WRONGCAT_HPP
