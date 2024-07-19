/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 17:17:30 by jmolenaa      #+#    #+#                 */
/*   Updated: 2024/07/19 10:26:15 by jmolenaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

#define REDSTRING(str) RED str RESET
#define GREENSTRING(str) GREEN str RESET
#define CYANSTRING(str) CYAN str RESET
#define YELLOWSTRING(str) YELLOW str RESET
#define BLUESTRING(str) BLUE str RESET

#endif

