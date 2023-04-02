/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:53 by makurz            #+#    #+#             */
/*   Updated: 2023/04/02 19:51:04 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_parse_specifier(char c, va_list args)
{
	int		printed;

	printed = 0;
	if (c == 'c')
		printed = ft_putchar(va_arg(args, int));
	else if (c == 's')
		printed = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		printed = ft_putnbr_base(va_arg(args, size_t), 10, c, printed);
	else if (c == 'i' || c == 'd')
		printed = ft_putnbr_base(va_arg(args, long), 10, c, printed);
	else if (c == 'u')
		printed = ft_putnbr_base(va_arg(args, unsigned int), 10, c, printed);
	else if (c == 'x' || c == 'X')
		printed = ft_putnbr_base(va_arg(args, unsigned int), 16, c, printed);
	else if (c == '%')
		printed = ft_putchar('%');
	return (printed);
}

int	ft_printf(const char *s, ...)
{
	int			printed;
	int			i;
	va_list		args;

	printed = 0;
	i = -1;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[++i] != '\0')
	{
		if (s[i] != '%')
			printed += ft_putchar(s[i]);
		else if (s[i++] == '%')
			printed += ft_parse_specifier(s[i++], args);
	}
	va_end(args);
	// printf("#number: %i\n", printed);
	return (printed);
}

int	main(void)
{
	ft_printf("Hello %x", 16);
	return (0);
}

