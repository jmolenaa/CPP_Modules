/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:10:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:10:05 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP04_CAT_HPP
#define CPP04_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

private:
	Brain*	headGlobes;

public:
	// OCF stuff
	Cat();
	Cat(Cat const& src);
	Cat&	operator=(Cat const& rhs);
	~Cat();

	void makeSound() const override;
};


#endif //CPP04_CAT_HPP
