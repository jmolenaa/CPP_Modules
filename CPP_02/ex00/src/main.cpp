/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 20:55:30 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/02/04 20:55:30 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(){

	Fixed a;
	std :: cout << "\n";

	Fixed b( a );
	std :: cout << "\n";

	Fixed c;
	std :: cout << "\n";

	c = b;
	std :: cout << "\n";


	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std :: cout << "\n";

	Fixed d = b;

	std :: cout << "\n";

	d.setRawBits(40);
	std::cout << d.getRawBits() << "\n";

	std :: cout << "\n";

	return 0;
}

