/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 09:11:26 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/08 09:11:26 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 8-4-24.
//

#ifndef CPP_06_SCALARCONVERTER_HPP
#define CPP_06_SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

private:
	ScalarConverter() = default;
	ScalarConverter(ScalarConverter const& src) = default;
	ScalarConverter&	operator=(ScalarConverter const& rhs) = default;
	~ScalarConverter() = default;

public:
	static void	convert(std::string const& inputStr);
};

#endif //CPP_06_SCALARCONVERTER_HPP
