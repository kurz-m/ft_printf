/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:24:00 by makurz            #+#    #+#             */
/*   Updated: 2023/04/03 15:51:31 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_putchar(char c, int *printed)
{
	write(1, &c, 1);
	(*printed)++;
}

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
