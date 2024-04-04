/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 08:15:13 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/02 08:15:13 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "defines.h"
#include "ShrubberyCreationForm.hpp"

int	main() {

	Bureaucrat	a("Chad", 145);

	ShrubberyCreationForm	b("Ni");
	a.signForm(b);
	a.executeForm(b);
}
