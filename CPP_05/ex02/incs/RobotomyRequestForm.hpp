/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:37:42 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/04 16:37:42 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 4-4-24.
//

#ifndef CPP_05_ROBOTOMYREQUESTFORM_HPP
#define CPP_05_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const& src);
	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
	explicit  RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	std::string	getTarget() const;

private:
	void _executeForm() const override;
	std::string	_target;
};


#endif //CPP_05_ROBOTOMYREQUESTFORM_HPP
