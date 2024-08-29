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
	int			_year;
	int			_month;
	int			_day;

	void	_setYear(std::string const& year);
	void	_setMonth(std::string const& month);
	void	_setDay(std::string const& day);
	void	_validateDate() const;

public:
	Date() = default;
	Date(Date const& src) = default;
	explicit Date(std::string const& newDate);
	~Date() = default;
	Date&	operator=(Date const& rhs) = default;

	int					getYear() const;
	int					getMonth() const;
	int					getDay() const;
	void 				setDate(std::string const &newDate);

	bool	operator==(Date const& other) const;
	bool	operator<(Date const& rhs) const;
	bool	operator<=(Date const& rhs) const;
	bool	operator>(Date const& rhs) const;
	bool	operator>=(Date const& rhs) const;
	Date&	operator--();

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
			std::size_t hash1 = std::hash<int>()(date.getDay());
			std::size_t hash2 = std::hash<int>()(date.getMonth());
			std::size_t hash3 = std::hash<int>()(date.getYear());

			return (hash1 ^ (hash2 << 1) ^ (hash3 << 2));
		}
	};
}


#endif //CPP09_DATE_HPP
