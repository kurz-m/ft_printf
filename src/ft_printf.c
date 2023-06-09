/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:53 by makurz            #+#    #+#             */
/*   Updated: 2023/04/21 16:05:02 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

// This function parses the specifier and calls the relevant function.
int	ft_parse_specifier(char c, va_list args, int *printed)
{
	int		check;

	check = TRUE;
	if (c == 'c')
		check &= f_putchar(va_arg(args, int), printed);
	else if (c == 's')
		check &= f_putstr(va_arg(args, char *), printed);
	else if (c == 'p')
		check &= ft_putptr(va_arg(args, void *), printed);
	else if (c == 'i' || c == 'd')
		check &= ft_putnbr((long) va_arg(args, int), printed);
	else if (c == 'u')
		check &= ft_putunbr(va_arg(args, unsigned int), printed);
	else if (c == 'x')
		check &= ft_putnbrbase(va_arg(args, unsigned int), LHEX, printed);
	else if (c == 'X')
		check &= ft_putnbrbase(va_arg(args, unsigned int), UHEX, printed);
	else if (c == '%')
		check &= f_putchar('%', printed);
	return (check);
}

// Main function which walks through the given string.
int	ft_printf(const char *format, ...)
{
	int		printed;
	int		check;
	int		i;
	va_list	args;

	printed = 0;
	i = -1;
	check = TRUE;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[++i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		if (format[i] != '%')
			check &= f_putchar(format[i], &printed);
		else if (format[i++] == '%')
			check &= ft_parse_specifier(format[i], args, &printed);
		if (check == FALSE)
			return (-1);
	}
	va_end(args);
	return (printed);
}
