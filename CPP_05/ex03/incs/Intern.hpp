/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 07:24:31 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/08 07:24:31 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 8-4-24.
//

#ifndef CPP_05_INTERN_HPP
#define CPP_05_INTERN_HPP

#include "AForm.hpp"

class Intern {

public:
	Intern() = default;
	Intern(Intern const& src) = default;
	Intern&	operator=(Intern const& rhs) = default;
	~Intern() = default;

	AForm*	makeForm(std::string formName, std::string target);

};


#endif //CPP_05_INTERN_HPP
