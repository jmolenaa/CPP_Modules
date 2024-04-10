/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 11:52:53 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/10 11:52:53 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 10-4-24.
//

#ifndef CPP_06_DATA_HPP
#define CPP_06_DATA_HPP


class Data {

private:
	Data(Data const& src) = default;
	Data&	operator=(Data const& rhs) = default;

public:
	Data() = default;
	~Data() = default;

	int	i;

};


#endif //CPP_06_DATA_HPP
