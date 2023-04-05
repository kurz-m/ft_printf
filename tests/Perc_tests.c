/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Perc_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:30:08 by makurz            #+#    #+#             */
/*   Updated: 2023/04/05 06:48:21 by makurz           ###   ########.fr       */
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

TestSuite(perc_test, .init=setup);

Test(perc_test, p_basic_1)
{
	ft_printf("%%");
	cr_expect_stdout_eq_str("%");
}

Test(perc_test, p_basic_2)
{
	ft_printf("%%%%%%%%");
	cr_expect_stdout_eq_str("%%%%");
}

Test(perc_test, p_basic_3)
{
	ft_printf("What can a %% do?");
	cr_expect_stdout_eq_str("What can a % do?");
}

Test(perc_test, p_basic_4)
{
	ft_printf("%% helol %%%%");
	cr_expect_stdout_eq_str("% helol %%");
}

Test(perc_test, p_basic_5)
{
	ft_printf("%%%%%% What is this %% sign?");
	cr_expect_stdout_eq_str("%%% What is this % sign?");
}

Test(perc_test, p_basic_6)
{
	ft_printf("              %%");
	cr_expect_stdout_eq_str("              %");
}
