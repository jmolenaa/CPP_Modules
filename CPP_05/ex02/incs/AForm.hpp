/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 10:13:51 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/02 10:13:51 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 2-4-24.
//

#ifndef CPP_05_FORM_HPP
#define CPP_05_FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	std::string const	_name;
	bool				_isSigned = false;
	int const			_signGrade;
	int const			_executeGrade;
	void				_checkGrades() const;

public:
	AForm();
	AForm(AForm const& src);
	AForm&	operator=(AForm const& rhs);
	AForm(std::string name, int signGrade, int executeGrade);
	~AForm();

	int			getSignGrade() const;
	int			getExecuteGrade() const;
	bool		getIsSigned() const;
	std::string	getName() const;

	void			beSigned(Bureaucrat const& signee);
	void			execute(Bureaucrat const& executor) const;
	virtual void	_executeForm() const = 0;

	class GradeTooHighException: public std::exception {
	public:
		char const*	what() const noexcept override;
	};

	class GradeTooLowException: public std::exception {
	public:
		char const*	what() const noexcept override;
	};

	class FormAlreadySignedException: public std::exception {
	public:
		char const*	what() const noexcept override;
	};

	class FormNotSignedException : public std::exception {
	public:
		char const* what() const noexcept override;
	};

};

std::ostream&	operator<<(std::ostream& outstream, AForm const& rhs);

#endif //CPP_05_FORM_HPP
