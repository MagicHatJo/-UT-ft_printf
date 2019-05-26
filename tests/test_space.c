/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:48:43 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 15:48:44 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_unit_test.h"

static int	test_01(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%      i 42 == |%      i|\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%      i 42 == |%      i|\n", 42);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_02(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%% i -42 == |% i|\n", -42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%% i -42 == |% i|\n", -42);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_03(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%% 4i 42 == |% 4i|\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%% 4i 42 == |% 4i|\n", 42);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_space(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("space: ");
	load_test(&testlist, "Test", &test_01);
	load_test(&testlist, "Test", &test_02);
	load_test(&testlist, "Test", &test_03);
	return (launch_tests(&testlist));
}