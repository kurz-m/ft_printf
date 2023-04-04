/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ID_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:24 by makurz            #+#    #+#             */
/*   Updated: 2023/04/04 15:22:29 by makurz           ###   ########.fr       */
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

TestSuite(s_basic, .init=setup);

Test(s_basic, basic_1)
{
	ft_printf("Hello %s", "makurz");
	cr_expect_stdout_eq_str("Hello makurz");
}

Test(s_basic, basic_2)
{
	ft_printf("%s is %s", "This", "a test");
	cr_expect_stdout_eq_str("This is a test");
}

Test(s_basic, basic_3)
{
	ft_printf("%s %s %s", "What", "is", "a test");
	cr_expect_stdout_eq_str("What is a test");
}

Test(s_basic, basic_4)
{
	ft_printf("%s", "Loooooooooooooooooong string in here");
	cr_expect_stdout_eq_str("Loooooooooooooooooong string in here");
}

TestSuite(c_basic, .init=setup);

Test(c_basic, basic_1)
{
	ft_printf("%c is %c", 'a', 'b');
	cr_expect_stdout_eq_str("a is b");
}

Test(c_basic, basic_2)
{
	ft_printf("%c%c%c%c%c", 'a', 'b', 'c', 'd', 'f');
	cr_expect_stdout_eq_str("abcdf");
}

Test(c_basic, basic_3)
{
	ft_printf("%c%c%c%c", 'a', 't', 'f', 't');
	cr_expect_stdout_eq_str("atft");
}

Test(c_basic, basic_4)
{
	ft_printf("this is only one char at the end %c", 'c');
	cr_expect_stdout_eq_str("this is only one char at the end c");
}

TestSuite(p_test, .init=setup);

Test(p_test, p_basic_1)
{
	char	buf[30];
	bzero(buf, 30);
	setbuf(stderr, buf);
	fprintf(stderr, "%p", NULL);
	setbuf(stderr, NULL);
	ft_printf("%p", NULL);
	cr_expect_stdout_eq_str(buf);
}

