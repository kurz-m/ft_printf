/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xx_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:35 by makurz            #+#    #+#             */
/*   Updated: 2023/04/05 06:33:41 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "../include/ft_printf.h"

void setup(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

TestSuite(X_test, .init=setup);

Test(X_test, X_basic_1)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "testing %X %X %X", 0, 53, 53);
	setbuf(stderr, NULL);
	ft_printf("testing %X %X %X", 0, 53, 53);
	cr_expect_stdout_eq_str(buf);
}

Test(X_test, X_basic_2)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%X", UINT_MAX);
	setbuf(stderr, NULL);
	ft_printf("%X", UINT_MAX);
	cr_expect_stdout_eq_str(buf);
}

Test(X_test, X_basic_4)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%X%X%X%X", INT_MAX, INT_MIN, UINT_MAX, UINT_MAX);
	setbuf(stderr, NULL);
	ft_printf("%X%X%X%X", INT_MAX, INT_MIN, UINT_MAX, UINT_MAX);
	cr_expect_stdout_eq_str(buf);
}
TestSuite(x_test, .init=setup);

Test(x_test, x_basic_1)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "testing %x %x %x", INT_MIN, INT_MAX, INT_MAX);
	setbuf(stderr, NULL);
	ft_printf("testing %x %x %x", INT_MIN, INT_MAX, INT_MAX);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, x_basic_2)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%x", UINT_MAX);
	setbuf(stderr, NULL);
	ft_printf("%x", UINT_MAX);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, x_basic_3)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%x", 0);
	setbuf(stderr, NULL);
	ft_printf("%x", 0);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, x_basic_4)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%x%x%x%x", 0, 0, 0, 0);
	setbuf(stderr, NULL);
	ft_printf("%x%x%x%x", 0, 0, 0, 0);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, x_basic_5)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "Ordinary string nb: %x", -532342);
	setbuf(stderr, NULL);
	ft_printf("Ordinary string nb: %x", -532342);
	cr_expect_stdout_eq_str(buf);
}
