/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 13:27:50 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/12/29 13:27:54 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {

private:

	Contact	_contacts[8];
	int		_phonebookSize;
	void	_displayAllContacts();
	int		_askForIndex() const;

public:
	Phonebook();
	~Phonebook();
	void	search();
	void	addContact();
};

#endif