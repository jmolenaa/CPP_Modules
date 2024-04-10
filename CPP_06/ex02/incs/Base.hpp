/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 12:12:09 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/04/10 12:12:09 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by jmolenaa on 10-4-24.
//

#ifndef CPP_06_BASE_HPP
#define CPP_06_BASE_HPP


class Base {

public:
	virtual ~Base() = default;
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);


#endif //CPP_06_BASE_HPP
