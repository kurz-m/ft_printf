/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:01 by makurz            #+#    #+#             */
/*   Updated: 2023/04/04 15:06:04 by makurz           ###   ########.fr       */
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
