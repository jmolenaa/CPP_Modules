/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 08:16:00 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/02 08:16:00 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 2-4-24.
//

#ifndef CPP_05_BUREAUCRAT_HPP
#define CPP_05_BUREAUCRAT_HPP

#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {

private:
	std::string const	_name;
	int					_grade;
	void				setGrade(int newGrade);

public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const& src);
	Bureaucrat&	operator=(Bureaucrat const& rhs);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	int			getGrade() const;
	std::string	getName() const;

	void		incrementGrade();
	void		decrementGrade();

	void		signForm(Form & formToSign) const;

	class GradeTooHighException: public std::exception {
	public:
		char const*	what() const noexcept override;
	};

	class GradeTooLowException: public std::exception {
	public:
		char const*	what() const noexcept override;
	};

};

std::ostream&	operator<<(std::ostream& outstream, Bureaucrat const& rhs);

#endif //CPP_05_BUREAUCRAT_HPP
