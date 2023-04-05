/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:53 by makurz            #+#    #+#             */
/*   Updated: 2023/04/05 18:07:18 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>

// This function parses the specifier and calls the relevant function.
void	ft_parse_specifier(char c, va_list args, int *printed)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), printed);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), printed);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), printed);
	else if (c == 'i' || c == 'd')
		ft_putnbr_base((long) va_arg(args, int), 10, c, printed);
	else if (c == 'u')
		ft_putnbr_base((long) va_arg(args, unsigned int), 10, c, printed);
	else if (c == 'x' || c == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), 16, c, printed);
	else if (c == '%')
		ft_putchar('%', printed);
}

// Main function which walks through the given string.
int	ft_printf(const char *format, ...)
{
	int		printed;
	int		i;
	va_list	args;

	printed = 0;
	i = -1;
	va_start(args, format);
	if (!format)
		return (0);
	while (format[++i])
	{
		if (format[i] == '%' && !format[i + 1])
		{
			va_end(args);
			return (printed);
		}
		if (format[i] != '%')
			ft_putchar(format[i], &printed);
		else if (format[i++] == '%')
			ft_parse_specifier(format[i], args, &printed);
	}
	va_end(args);
	return (printed);
}
