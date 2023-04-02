/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:53 by makurz            #+#    #+#             */
/*   Updated: 2023/04/02 16:52:33 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>

int	ft_parse_specifier(char c, va_list args)
{
	int		printed;

	printed = 0;
	if (c == 'c')
		printed += ft_putchar(va_arg(args, int));
	return (printed);
}
