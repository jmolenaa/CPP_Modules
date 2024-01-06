/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:45:24 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/06 12:45:26 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	std :: string	hi = "HI THIS IS BRAIN";
	std :: string*	stringPTR = &hi;
	std :: string&	stringREF = hi;

	std :: cout	<< "Memory addresses\n"
				<< &hi << "\n"
				<< stringPTR << "\n"
				<< &stringREF << "\n\n";

	std :: cout	<< "Values\n"
				<< hi << "\n"
				<< *stringPTR << "\n"
				<< stringREF << "\n";

}
