/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 11:52:07 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/10 11:52:07 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 10-4-24.
//

#ifndef CPP_06_SERIALIZER_HPP
#define CPP_06_SERIALIZER_HPP

#include <cstdint>

#include "Data.hpp"

class Serializer {

private:
	Serializer() = default;
	Serializer(Serializer const& src) = default;
	Serializer&	operator=(Serializer const& rhs) = default;
	~Serializer() = default;

public:
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);

};


#endif //CPP_06_SERIALIZER_HPP
