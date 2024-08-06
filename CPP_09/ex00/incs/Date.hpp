/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Date.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 17:36:21 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/30 17:36:21 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 30-7-24.
//

#ifndef CPP09_DATE_HPP
#define CPP09_DATE_HPP

#include <iostream>

class Date {

private:
	std::string	_date;
	int			_year;
	int			_month;
	int			_day;

	void	_setYear(std::string const& year);
	void	_setMonth(std::string const& month);
	void	_setDay(std::string const& day);
	void	_validateDate() const;

public:
	Date() = default;
	Date(Date const& src);
	explicit Date(std::string const& newDate);
	~Date() = default;
	Date&	operator=(Date const& rhs);

	std::string const&	getDate() const;
	int					getYear() const;
	int					getMonth() const;
	int					getDay() const;
	void 				setDate(std::string const &newDate);

	bool	operator==(Date const& other) const;

	class InvalidDateFormatException : public std::exception {
	public:
		explicit	InvalidDateFormatException(std::string const& reason);
		char const* what() const noexcept override;

	private:
		std::string	_reason;
	};

};

namespace std {
	template <>
	struct hash<Date> {
		std::size_t operator()(Date const& date) const {
			return (std::hash<std::string>()(date.getDate()));
		}
	};
}


#endif //CPP09_DATE_HPP
