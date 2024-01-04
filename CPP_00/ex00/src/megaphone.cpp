/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 13:27:57 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/12/29 13:27:57 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    std :: string	word;

    if (argc == 1)
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
    {
        word = argv[i];
        for (char &c : word)
            c = toupper(c);
        std :: cout << word;
    }
    std :: cout << std :: endl;
    return (0);
}
