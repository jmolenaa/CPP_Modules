/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:37:41 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/04 16:37:41 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 4-4-24.
//

#ifndef CPP_05_SHRUBBERYCREATIONFORM_HPP
#define CPP_05_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	std::string	getTarget() const;

private:
	void		_executeForm() const override;
	std::string	_target;
};


#endif //CPP_05_SHRUBBERYCREATIONFORM_HPP
