/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xx_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:35 by makurz            #+#    #+#             */
/*   Updated: 2023/04/04 17:48:37 by makurz           ###   ########.fr       */
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

Test(X_test, u_basic_1)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "testing %u %u %u", (unsigned int) -34, 53, 53);
	setbuf(stderr, NULL);
	ft_printf("testing %u %u %u", (unsigned int) -34, 53, 53);
	cr_expect_stdout_eq_str(buf);
}

Test(X_test, u_basic_2)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%X", UINT_MAX);
	setbuf(stderr, NULL);
	ft_printf("%X", UINT_MAX);
	cr_expect_stdout_eq_str(buf);
}

Test(X_test, u_basic_3)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%u", (unsigned int) INT_MAX);
	setbuf(stderr, NULL);
	ft_printf("%u", (unsigned int) INT_MAX);
	cr_expect_stdout_eq_str(buf);
}

Test(X_test, u_basic_4)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%u%u%u%u", 0, 0, 0, 0);
	setbuf(stderr, NULL);
	ft_printf("%u%u%u%u", 0, 0, 0, 0);
	cr_expect_stdout_eq_str(buf);
}

TestSuite(x_test, .init=setup);

Test(x_test, u_basic_1)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "testing %u %u %u", (unsigned int) -34, 53, 53);
	setbuf(stderr, NULL);
	ft_printf("testing %u %u %u", (unsigned int) -34, 53, 53);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, u_basic_2)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%u", UINT_MAX);
	setbuf(stderr, NULL);
	ft_printf("%u", UINT_MAX);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, u_basic_3)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%u", (unsigned int) INT_MAX);
	setbuf(stderr, NULL);
	ft_printf("%u", (unsigned int) INT_MAX);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, u_basic_4)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%u%u%u%u", 0, 0, 0, 0);
	setbuf(stderr, NULL);
	ft_printf("%u%u%u%u", 0, 0, 0, 0);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, u_basic_5)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "Ordinary string nb: %u", -532342);
	setbuf(stderr, NULL);
	ft_printf("Ordinary string nb: %u", -532342);
	cr_expect_stdout_eq_str(buf);
}

Test(x_test, u_basic_6)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%% %u from %% %u", 34241, -43241);
	setbuf(stderr, NULL);
	ft_printf("%% %u from %% %u", 34241, -43241);
	cr_expect_stdout_eq_str(buf);
}
