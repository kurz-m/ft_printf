/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:24:00 by makurz            #+#    #+#             */
/*   Updated: 2023/04/16 15:38:45 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

// Returns the string length of the given string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

// Prints the given char and counts the 'printed' to keep
// track of the printed characters.
void	ft_putchar(char c, int *printed)
{
	ssize_t		exit_code;

	exit_code = write(1, &c, 1);
	if (exit_code == -1)
		_exit(-1);
	(*printed)++;
}

// Prints the given string and adds the printed chars 
// to the 'printed' variable to keep track of the printed characters.
void	ft_putstr(char *s, int *printed)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*printed) += 6;
	}
	else
	{
		write(1, s, ft_strlen(s));
		(*printed) += ft_strlen(s);
	}
}
