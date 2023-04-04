/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ID_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:24 by makurz            #+#    #+#             */
/*   Updated: 2023/04/04 17:40:07 by makurz           ###   ########.fr       */
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

TestSuite(i_basic, .init=setup);

Test(i_basic, basic_1)
{
	ft_printf("%i%i%i%i", INT_MAX, 23, 42, 21);
	cr_expect_stdout_eq_str("2147483647234221");
}

Test(i_basic, basic_2)
{
	ft_printf("%i, newtest: %i", INT_MIN, 0);
	cr_expect_stdout_eq_str("-2147483648, newtest: 0");
}

Test(i_basic, basic_3)
{
	ft_printf("%i", INT_MIN);
	cr_expect_stdout_eq_str("-2147483648");
}

Test(i_basic, basic_4)
{
	ft_printf("%i", 107);
	cr_expect_stdout_eq_str("107");
}

TestSuite(d_basic, .init=setup);

Test(d_basic, basic_1)
{
	ft_printf("%d is %d", INT_MAX, INT_MIN);
	cr_expect_stdout_eq_str("2147483647 is -2147483648");
}

Test(d_basic, basic_2)
{
	ft_printf("%d%d%d%d%d", 10, -329, -239,-29, 29);
	cr_expect_stdout_eq_str("10-329-239-2929");
}

Test(d_basic, basic_3)
{
	ft_printf(" l%d%d%d%d ", 231, 210, 1, 0);
	cr_expect_stdout_eq_str(" l23121010 ");
}

Test(d_basic, basic_4)
{
	ft_printf("testnb: %d %d %d", 21, 42, 4242);
	cr_expect_stdout_eq_str("testnb: 21 42 4242");
}
