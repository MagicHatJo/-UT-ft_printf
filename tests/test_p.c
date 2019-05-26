/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:44:21 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 14:44:22 by jochang          ###   ########.fr       */
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
	char	c;

	c = 0;
	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%p\n", &c);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%p\n", &c);
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
	char	*str;

	str = "pouet";
	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%p\n", str);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%p\n", str);
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
	char	*str;

	str = "pouet";
	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%p\n", &str);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%p\n", &str);
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
	char	*str;

	str = NULL;
	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%p\n", str);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%p\n", str);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_p(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("p: ");
	load_test(&testlist, "Test", &test_01);
	load_test(&testlist, "Test", &test_02);
	load_test(&testlist, "Test", &test_03);
	load_test(&testlist, "Test", &test_04);
	return (launch_tests(&testlist));
}