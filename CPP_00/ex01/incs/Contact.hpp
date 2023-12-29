/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 13:27:45 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/12/29 13:27:46 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

private:

	std :: string	_firstName;
	std :: string	_lastName;
	std :: string	_nickName;
	std :: string	_phoneNumber;
	std :: string	_darkestSecret;

public:
	bool	setFirstName();
	bool	setLastName();
	bool	setNickName();
	bool	setPhoneNumber();
	bool	setDarkestSecret();

//	Contact();
//	~Contact();

};

#endif