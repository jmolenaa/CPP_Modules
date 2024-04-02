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

	class GradeTooHighException: public std::exception {
	public:
		char const*	what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		char const*	what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& outstream, Bureaucrat const& rhs);

#endif //CPP_05_BUREAUCRAT_HPP
