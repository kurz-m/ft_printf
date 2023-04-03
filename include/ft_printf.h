/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:45:06 by makurz            #+#    #+#             */
/*   Updated: 2023/04/03 14:39:28 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *printed);
void	ft_putstr(char *s, int *printed);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(long nb, int base, char c, int *count);
void	ft_putptr(void *ptr, int *printed);
void	ft_putnbr_hex(size_t nb, size_t base, char c, int *printed);

#endif
