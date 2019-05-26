/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:32:39 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 16:32:39 by jochang          ###   ########.fr       */
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
	libc_retval = printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
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
	libc_retval = printf("%% 4.5i 42 == |% 4.5i|\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%% 4.5i 42 == |% 4.5i|\n", 42);
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
	libc_retval = printf("%%04.5i 42 == |%04.5i|\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
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
	libc_retval = printf("%%04.3i 42 == |%04.3i|\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
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
	libc_retval = printf("%%04.2i 42 == |%04.2i|\n", 42);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_precision(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("preci: ");
	load_test(&testlist, "Test", &test_01);
	load_test(&testlist, "Test", &test_02);
	load_test(&testlist, "Test", &test_03);
	load_test(&testlist, "Test", &test_04);
	load_test(&testlist, "Test", &test_05);
	return (launch_tests(&testlist));
}