/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:53:30 by jochang           #+#    #+#             */
/*   Updated: 2019/05/25 16:53:31 by jochang          ###   ########.fr       */
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
	libc_retval = printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &n);
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &n);
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
	libc_retval = printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n');
	capture_get(libc_buf, BUF_SIZE);
	ft_retval = ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n');
	capture_get(ft_buf, BUF_SIZE);
	capture_close();
	result = !strcmp(libc_buf, ft_buf) ? 1 : 0;
	result &= libc_retval == ft_retval;
	return (result);
}

int		test_mix(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("  mix: ");
	load_test(&testlist, "Test", &test_01);
	load_test(&testlist, "Test", &test_02);
	return (launch_tests(&testlist));
}