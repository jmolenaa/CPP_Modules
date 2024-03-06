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
	// Parameterized constr
	Fixed(int val);
	Fixed(float val);
	// Copy constr
	Fixed(Fixed const & src);
	// Assignment operator overload
	Fixed&	operator=(Fixed const & rhs);
	// Destructor
	~Fixed();


	int		getRawBits() const;
	void	setRawBits(int raw);

	float	toFloat() const;
	int		toInt() const;

private:
	static int const	_fractional_bits = 8;
	int					_value;

};

std::ostream&	operator<<(std::ostream& outstream, Fixed const & rhs);

#endif