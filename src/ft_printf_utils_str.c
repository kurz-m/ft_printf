/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:24:00 by makurz            #+#    #+#             */
/*   Updated: 2023/04/21 11:30:40 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

// Returns the string length of the given string.
// WARNING: Can be removed upon merging
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
int	f_putchar(char c, int *printed)
{
	ssize_t		check;

	check = write(1, &c, 1);
	if (check == -1)
		return (FALSE);
	return ((*printed)++, TRUE);
}

// Prints the given string and adds the printed chars 
// to the 'printed' variable to keep track of the printed characters.
int	f_putstr(char *s, int *printed)
{
	ssize_t		check;

	if (s == NULL)
	{
		check = write(1, "(null)", 6);
		if (check == -1)
			return (FALSE);
		(*printed) += 6;
	}
	else
	{
		check = write(1, s, ft_strlen(s));
		if (check == -1)
			return (FALSE);
		(*printed) += ft_strlen(s);
	}
	return (TRUE);
}
