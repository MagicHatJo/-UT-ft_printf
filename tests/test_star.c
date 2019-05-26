/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:58:35 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 16:58:35 by jochang          ###   ########.fr       */
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
	libc_retval = printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
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
	libc_retval = printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
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
	libc_retval = printf("%%*i 42 == |%*i|\n", 5, 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_04(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%*i 42 == |%*i|\n", 3, 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_05(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%*i 42 == |%*i|\n", 2, 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%*i 42 == |%*i|\n", 2, 42);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_star(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf(" star: ");
	load_test(&testlist, "Test", &test_01);
	load_test(&testlist, "Test", &test_02);
	load_test(&testlist, "Test", &test_03);
	load_test(&testlist, "Test", &test_04);
	load_test(&testlist, "Test", &test_05);
	return (launch_tests(&testlist));
}