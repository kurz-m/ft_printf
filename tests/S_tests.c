/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   S_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:12 by makurz            #+#    #+#             */
/*   Updated: 2023/04/04 15:07:13 by makurz           ###   ########.fr       */
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
