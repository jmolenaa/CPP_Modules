/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmolenaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:03:10 by jmolenaa          #+#    #+#             */
/*   Updated: 2024/01/07 14:03:12 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl{

private:
	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;

public:
	Harl();
	~Harl();
	void	complain(std::string level) const;

};

#endif
