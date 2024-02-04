/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/04 20:55:11 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/02/04 20:55:11 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

public:

	// Default
	Fixed();
	// Copy constr
	Fixed(Fixed const & src);
	// Assignment operator overload
	Fixed&	operator=(Fixed const & rhs);
	// Destructor
	~Fixed();


	int		getRawBits() const;
	void	setRawBits(int raw);


private:
	static int const	_fractional_bits = 8;
	int					_value;

};

#endif