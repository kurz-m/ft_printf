/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:24:00 by makurz            #+#    #+#             */
/*   Updated: 2023/04/04 08:20:14 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_base(long nb, int base, char c, int *printed)
{
	if (nb < 0)
	{
		ft_putchar('-', printed);
		nb *= -1;
	}
	if (c == 'p' || c == 'x')
		c = 'a';
	else if (c == 'X')
		c = 'A';
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, base, c, printed);
		ft_putnbr_base(nb % base, base, c, printed);
	}
	else if (nb < 10)
		ft_putchar(nb % base + 48, printed);
	else
		ft_putchar(nb % base + c - 10, printed);
}

void	ft_putnbr_hex(size_t nb, size_t base, char c, int *printed)
{
	if (c == 'p' || c == 'x')
		c = 'a';
	else if (c == 'X')
		c = 'A';
	if (nb >= base)
	{
		ft_putnbr_hex(nb / base, base, c, printed);
		ft_putnbr_hex(nb % base, base, c, printed);
	}
	else if (nb < 10)
		ft_putchar(nb % base + 48, printed);
	else
		ft_putchar(nb % base + c - 10, printed);
}

void	ft_putptr(void *ptr, int *printed)
{
	size_t		ui;

	if (ptr != NULL)
	{
		ui = (size_t) ptr;
		ft_putstr("0x", printed);
		ft_putnbr_hex(ui, 16, 'p', printed);
	}
	else
		ft_putstr("0x0", printed);
}
