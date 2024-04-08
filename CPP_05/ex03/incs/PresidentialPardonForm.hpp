/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:37:45 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/04 16:37:45 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 4-4-24.
//

#ifndef CPP_05_PRESIDENTIALPARDONFORM_HPP
#define CPP_05_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);
	explicit PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

	std::string	getTarget() const;

private:
	void _executeForm() const override;
	std::string	_target;
};


#endif //CPP_05_PRESIDENTIALPARDONFORM_HPP
