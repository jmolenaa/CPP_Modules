/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 12:12:17 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/03/27 12:12:17 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP04_BRAIN_HPP
#define CPP04_BRAIN_HPP

#include <iostream>

class Brain {

private:
	std::string	_ideas[100];

public:
	// OCF stuff
	Brain();
	Brain(Brain const& src);
	Brain&	operator=(Brain const& rhs);
	~Brain();
};


#endif //CPP04_BRAIN_HPP
