/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:10:08 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/26 17:10:08 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP04_DOG_HPP
#define CPP04_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:
	Brain*	headGlobes;

public:
	// OCF stuff
	Dog();
	Dog(Dog const& src);
	Dog&	operator=(Dog const& rhs);
	~Dog();

	void makeSound() const override;

};


#endif //CPP04_DOG_HPP
