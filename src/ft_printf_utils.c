/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:24:00 by makurz            #+#    #+#             */
/*   Updated: 2023/04/02 21:17:29 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr_base(long nb, size_t base, char c, int count)
{
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (c == 'p' || c == 'x')
		c = 'a';
	else if (c == 'X')
		c = 'A';
	if (nb > base)
	{
		ft_putnbr_base(nb / base, base, c, count);
		ft_putnbr_base(nb % base, base, c, count);
	}
	else if (nb < 10)
		count += ft_putchar(nb + 48);
	else
		count += ft_putchar(nb + c - 10);
	return (count);
}
