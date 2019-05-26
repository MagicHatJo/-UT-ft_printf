/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:43:35 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 16:43:35 by jochang          ###   ########.fr       */
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
	unsigned char	a = -125;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned char		a = %hhu sizeof a = %lu\n", a, sizeof(a));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned char		a = %hhu sizeof a = %lu\n", a, sizeof(a));
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
	unsigned int b = -125;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned int		b = %u sizeof b = %lu\n", b, sizeof(b));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned int		b = %u sizeof b = %lu\n", b, sizeof(b));
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
	unsigned long c = -125;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned long		c = %lu sizeof c = %lu\n", c, sizeof(c));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned long		c = %lu sizeof c = %lu\n", c, sizeof(c));
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
	unsigned short d = -125;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned short		d = %hu sizeof d = %lu\n", d, sizeof(d));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned short		d = %hu sizeof d = %lu\n", d, sizeof(d));
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
	size_t e = -125;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("size_t			e = %zu sizeof e = %lu\n", e, sizeof(e));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("size_t			e = %zu sizeof e = %lu\n", e, sizeof(e));
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
	uintmax_t f = -125;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("uintmax_t		f = %ju sizeof f = %lu\n", f, sizeof(f));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("uintmax_t		f = %ju sizeof f = %lu\n", f, sizeof(f));
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
	unsigned long long	g = -125;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned long long	g = %llu sizeof g = %lu\n\n", g, sizeof(g));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned long long	g = %llu sizeof g = %lu\n\n", g, sizeof(g));
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
	unsigned char	a = 0;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned char		a = %hhu sizeof a = %lu\n", a, sizeof(a));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned char		a = %hhu sizeof a = %lu\n", a, sizeof(a));
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
	unsigned int b = 0;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned int		b = %u sizeof b = %lu\n", b, sizeof(b));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned int		b = %u sizeof b = %lu\n", b, sizeof(b));
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
	unsigned long c = 0;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned long		c = %lu sizeof c = %lu\n", c, sizeof(c));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned long		c = %lu sizeof c = %lu\n", c, sizeof(c));
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
	unsigned short d = 0;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned short		d = %hu sizeof d = %lu\n", d, sizeof(d));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned short		d = %hu sizeof d = %lu\n", d, sizeof(d));
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
	size_t e = 0;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("size_t			e = %zu sizeof e = %lu\n", e, sizeof(e));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("size_t			e = %zu sizeof e = %lu\n", e, sizeof(e));
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_13(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;
	uintmax_t f = 0;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("uintmax_t		f = %ju sizeof f = %lu\n", f, sizeof(f));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("uintmax_t		f = %ju sizeof f = %lu\n", f, sizeof(f));
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

static int	test_14(void)
{
	char	libc_buf[BUF_SIZE];
	char	ft_buf[BUF_SIZE];
	int		libc_retval;
	int		ft_retval;
	int		result;
	unsigned long long	g = 0;

	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("unsigned long long	g = %llu sizeof g = %lu\n\n", g, sizeof(g));
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("unsigned long long	g = %llu sizeof g = %lu\n\n", g, sizeof(g));
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_length(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("  len: ");
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
	load_test(&testlist, "Test", &test_13);
	load_test(&testlist, "Test", &test_14);
	return (launch_tests(&testlist));
}