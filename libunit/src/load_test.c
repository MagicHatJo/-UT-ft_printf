/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:46:40 by jochang           #+#    #+#             */
/*   Updated: 2019/05/19 17:46:40 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_unit_test **ptr, char *test_name, int (*func)(void))
{
	t_unit_test *testlist;

	if (!*ptr)
	{
		testlist = malloc(sizeof(t_unit_test));
		memset(testlist, 0, sizeof(t_unit_test));
		testlist->name = test_name;
		testlist->func = func;
		testlist->next = NULL;
		*ptr = testlist;
		return ;
	}
	testlist = *ptr;
	while (testlist->next)
		testlist = testlist->next;
	testlist->next = malloc(sizeof(t_unit_test));
	testlist = testlist->next;
	memset(testlist, 0, sizeof(t_unit_test));
	testlist->name = test_name;
	testlist->func = func;
	testlist->next = NULL;
	return ;
}
