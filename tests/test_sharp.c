/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sharp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:57:19 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 15:57:19 by jochang          ###   ########.fr       */
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
	libc_retval = printf("%%#X 42 ==  %#X\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%#X 42 ==  %#X\n", 42);
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
	libc_retval = printf("%%X 42 ==  %X\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%X 42 ==  %X\n", 42);
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
	libc_retval = printf("%%#o 0 ==  %#o\n", 0);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%#o 0 ==  %#o\n", 0);
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
	libc_retval = printf("%%o 0 ==  %o\n", 0);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%o 0 ==  %o\n", 0);
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
	libc_retval = printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_06(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%o INT_MAX ==  %o\n", INT_MAX);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_07(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_08(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%o INT_MIN ==  %o\n", INT_MIN);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_09(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_10(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%X INT_MIN ==  %X\n", INT_MIN);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_11(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_12(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%%X INT_MAX ==  %X\n", INT_MAX);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_sharp(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("sharp: ");
	load_test(&testlist, "Test", &test_01);
	load_test(&testlist, "Test", &test_02);
	load_test(&testlist, "Test", &test_03);
	load_test(&testlist, "Test", &test_04);
	load_test(&testlist, "Test", &test_05);
	load_test(&testlist, "Test", &test_06);
	load_test(&testlist, "Test", &test_07);
	load_test(&testlist, "Test", &test_08);
	load_test(&testlist, "Test", &test_09);
	load_test(&testlist, "Test", &test_10);
	load_test(&testlist, "Test", &test_11);
	load_test(&testlist, "Test", &test_12);
	return (launch_tests(&testlist));
}