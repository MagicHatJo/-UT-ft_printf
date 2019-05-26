/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:34:54 by jochang           #+#    #+#             */
/*   Updated: 2019/05/24 20:34:55 by jochang          ###   ########.fr       */
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
	libc_retval = printf("%d", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d", 42);
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
	libc_retval = printf("Kashim a %d histoires à raconter", 1001);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("Kashim a %d histoires à raconter", 1001);
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
	libc_retval = printf("Il fait au moins %d\n", -8000);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("Il fait au moins %d\n", -8000);
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
	libc_retval = printf("%d", -0);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d", -0);
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
	libc_retval = printf("%d", 0);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d", 0);
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
	libc_retval = printf("%d", INT_MAX);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d", INT_MAX);
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
	libc_retval = printf("%d", INT_MIN);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d", INT_MIN);
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
	libc_retval = printf("%d", INT_MIN - 1);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d", INT_MIN - 1);
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
	libc_retval = printf("%d", INT_MAX + 1);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d", INT_MAX + 1);
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
	libc_retval = printf("%%d 0000042 == |%d|\n", 0000042);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%d 0000042 == |%d|\n", 0000042);
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
	libc_retval = printf("%%d \t == |%d|\n", '\t');
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%d \t == |%d|\n", '\t');
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
	libc_retval = printf("%%d Lydie == |%d|\n", 'L' + 'y' + 'd' + 'i' + 'e');
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%d Lydie == |%d|\n", 'L' + 'y' + 'd' + 'i' + 'e');
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_d(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("d: ");
	load_test(&testlist, "42       Test", &test_01);
	load_test(&testlist, "Basic    Test", &test_02);
	load_test(&testlist, "Negative Test", &test_03);
	load_test(&testlist, "Negative Test", &test_04);
	load_test(&testlist, "Zero     Test", &test_05);
	load_test(&testlist, "INT_MAX  Test", &test_06);
	load_test(&testlist, "INT_MIN  Test", &test_07);
	load_test(&testlist, "Overflow Test", &test_08);
	load_test(&testlist, "Overflow Test", &test_09);
	load_test(&testlist, "Leading  Test", &test_10);
	load_test(&testlist, "ASCII    Test", &test_11);
	load_test(&testlist, "Add      Test", &test_12);
	return (launch_tests(&testlist));
}
