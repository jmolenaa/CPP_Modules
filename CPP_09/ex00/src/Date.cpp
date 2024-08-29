/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Date.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 17:36:14 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/30 17:36:14 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 30-7-24.
//

#include "Date.hpp"
#include <ctime>
#include <algorithm>

Date::Date(std::string const& newDate) {
	this->setDate(newDate);
}

void	Date::_validateDate() const {
	time_t		currentTime;
	struct tm*	infoAboutCurrentTime;

	time(&currentTime);
	infoAboutCurrentTime = localtime(&currentTime);
	infoAboutCurrentTime->tm_year = this->getYear();
	infoAboutCurrentTime->tm_mon = this->getMonth();
	infoAboutCurrentTime->tm_mday = this->getDay();
	mktime(infoAboutCurrentTime);
	if (infoAboutCurrentTime->tm_year != this->getYear() ||
		infoAboutCurrentTime->tm_mon != this->getMonth() ||
		infoAboutCurrentTime->tm_mday != this->getDay()) {
		throw Date::InvalidDateFormatException("invalid date");
	}
}

void Date::setDate(const std::string &newDate) {
	if (std::count(newDate.begin(), newDate.end(), '-') != 2) {
		throw Date::InvalidDateFormatException("missing year, month or day");
	}
	this->_setYear(newDate.substr(0, newDate.find('-')));
	this->_setMonth(newDate.substr(newDate.find('-') + 1, newDate.find_last_of('-') - newDate.find('-') - 1));
	this->_setDay(newDate.substr(newDate.find_last_of('-') + 1, std::string::npos));
	this->_validateDate();
}

int Date::getYear() const {
	return this->_year;
}

static void	validateString(std::string const& str, uint8_t digitNumber, std::string const& datePart) {
	if (str.find_first_not_of("0123456789") != std::string::npos) {
		throw Date::InvalidDateFormatException("invalid character in " + datePart);
	}
	if (str.size() != digitNumber) {
		throw Date::InvalidDateFormatException("invalid amount of digits in " + datePart + ", should be " + std::to_string(digitNumber));
	}
}

void Date::_setYear(std::string const& newYear) {
	validateString(newYear, 4, "year");
	this->_year = std::stoi(newYear);
	if (this->getYear() < 2009 || this->getYear() > 2022) {
		throw Date::InvalidDateFormatException("no data for given year");
	}
}

int Date::getMonth() const {
	return this->_month;
}

void Date::_setMonth(std::string const& newMonth) {
	validateString(newMonth, 2, "month");
	this->_month = std::stoi(newMonth) - 1;
}

int Date::getDay() const {
	return this->_day;
}

void Date::_setDay(std::string const& newDay) {
	validateString(newDay, 2, "day");
	this->_day = std::stoi(newDay);
}

bool Date::operator==(const Date &other) const {
	return (this->getYear() == other.getYear() && this->getMonth() == other.getMonth() && this->getDay() == other.getDay());
}

static struct tm*	getTimeStruct(Date const& date) {
	time_t		currentTime;
	struct tm*	infoAboutCurrentTime;

	time(&currentTime);
	infoAboutCurrentTime = localtime(&currentTime);
	infoAboutCurrentTime->tm_year = date.getYear();
	infoAboutCurrentTime->tm_mon = date.getMonth();
	infoAboutCurrentTime->tm_mday = date.getDay();
	return (infoAboutCurrentTime);
}

bool Date::operator<(const Date &rhs) const {
	return (mktime(getTimeStruct(*this)) < mktime(getTimeStruct(rhs)));
}

bool Date::operator>(const Date &rhs) const {
	return (mktime(getTimeStruct(*this)) > mktime(getTimeStruct(rhs)));
}

bool Date::operator<=(const Date &rhs) const {
	return (mktime(getTimeStruct(*this)) <= mktime(getTimeStruct(rhs)));
}

bool Date::operator>=(const Date &rhs) const {
	return (mktime(getTimeStruct(*this)) >= mktime(getTimeStruct(rhs)));
}

Date& Date::operator--() {
	--this->_day;
	struct tm*	timeStruct = getTimeStruct(*this);
	mktime(timeStruct);
	this->_day = timeStruct->tm_mday;
	this->_month = timeStruct->tm_mon;
	this->_year = timeStruct->tm_year;
	return *this;
}

Date::InvalidDateFormatException::InvalidDateFormatException(const std::string &reason) {
	this->_reason = "Invalid date format: " + reason;
}

char const *Date::InvalidDateFormatException::what() const noexcept {
	return (this->_reason.c_str());
}
