/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:55:46 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 14:55:46 by jochang          ###   ########.fr       */
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
	int		n;

	n = 42;
	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("LALALALALAL\n%n", &n);
	printf("%d\n", n);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("LALALALALAL\n%n", &n);
	ft_printf("%d\n", n);
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
	int		n;

	n = 42;
	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("Kashim a %d histoires à raconter\n%n", 1001, &n);
	printf("%d\n", n);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &n);
	ft_printf("%d\n", n);
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
	int		n;

	n = 42;
	result = 0;
	if (!capture_init())
		return (0);
	libc_retval = printf("%d%n", '\t', &n);
	printf("%d\n", n);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("%d%n", '\t', &n);
	ft_printf("%d\n", n);
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_n(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("n: ");
	load_test(&testlist, "Test", &test_01);
	load_test(&testlist, "Test", &test_02);
	load_test(&testlist, "Test", &test_03);
	return (launch_tests(&testlist));
}