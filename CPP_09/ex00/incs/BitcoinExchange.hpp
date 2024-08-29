/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 11:59:23 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/25 11:59:23 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 25-7-24.
//

#ifndef CPP_09_BITCOINEXCHANGE_HPP
#define CPP_09_BITCOINEXCHANGE_HPP

#include "Date.hpp"
#include <unordered_map>
#include <fstream>

class BitcoinExchange {

private:
	std::unordered_map<Date, float>	database;
	Date							earliestDate;
	Date							oldestDate;

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& src);
	BitcoinExchange&	operator=(BitcoinExchange const& rhs);
	explicit BitcoinExchange(std::string const& databaseName);
	~BitcoinExchange() = default;

	void	parseDatabase(std::ifstream& databaseFile);
	void	checkOldestEarliestValues(Date const& newDate);
	float	convertSingleValue(std::string const& date, float const& value);
	const Date &getEarliestDate() const;
	const Date &getOldestDate() const;

	class BitcoinExchangeException : public std::exception {
	public:
		explicit BitcoinExchangeException(std::string const &reason);

		char const *what() const noexcept override;

	private:
		std::string _reason;
	};

};


#endif //CPP_09_BITCOINEXCHANGE_HPP
