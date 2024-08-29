/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: janmolenaar <janmolenaar@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 12:07:26 by janmolenaar   #+#    #+#                 */
/*   Updated: 2024/08/28 12:07:26 by janmolenaar   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Jan Molenaar on 28/08/2024.
//

#ifndef CPP_09_RPN_HPP
#define CPP_09_RPN_HPP

#include <stack>
#include <string>

class RPN {

public:
	RPN() = default;
	RPN(RPN const& src) = default;
	RPN&	operator=(RPN const& rhs) = default;
	~RPN() = default;

	void	processExpression(std::string const& expressionString);
	int		handleOperation(char operato);
	int		popStack();

private:
	std::stack<int>	operands;
};


#endif //CPP_09_RPN_HPP
