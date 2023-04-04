/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:41 by makurz            #+#    #+#             */
/*   Updated: 2023/04/04 16:43:03 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/ft_printf.h"

void setup(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

TestSuite(p_test, .init=setup);

Test(p_test, p_basic_1)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%p", NULL);
	setbuf(stderr, NULL);
	ft_printf("%p", NULL);
	cr_expect_stdout_eq_str(buf);
}

Test(p_test, p_basic_2)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%p", (void *) -1242);
	setbuf(stderr, NULL);
	ft_printf("%p", (void *) -1242);
	cr_expect_stdout_eq_str(buf);
}

Test(p_test, p_basic_3)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%p", (void *) 342);
	setbuf(stderr, NULL);
	ft_printf("%p", (void *) 342);
	cr_expect_stdout_eq_str(buf);
}

Test(p_test, p_basic_4)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%p", (void *) 0);
	setbuf(stderr, NULL);
	ft_printf("%p", (void *) 0);
	cr_expect_stdout_eq_str(buf);
}

Test(p_test, p_basic_5)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%p", (void *) -42);
	setbuf(stderr, NULL);
	ft_printf("%p", (void *) -42);
	cr_expect_stdout_eq_str(buf);
}

Test(p_test, p_basic_6)
{
	char	buf[70];
	bzero(buf, 70);
	setbuf(stderr, buf);
	fprintf(stderr, "%p", (void *) 918);
	setbuf(stderr, NULL);
	ft_printf("%p", (void *) 918);
	cr_expect_stdout_eq_str(buf);
}

