/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:51:51 by jochang           #+#    #+#             */
/*   Updated: 2019/05/19 21:51:22 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int		fork_test(int (*f)())
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) == -1)
	{
		perror("fork()");
		return (0x42000001);
	}
	else if (!pid)
	{
		alarm(2);
		exit(f());
	}
	wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (0x42000000);
}

static char		*test_result_string(int code)
{
	if (code == 0)
		return (MSG_KO);
	if (code == 1)
		return (MSG_OK);
	if (code == 0x42000001)
		return (MSG_FORK_ERR);
	if (code == SIGBUS)
		return (MSG_BUS_ERR);
	if (code == SIGABRT)
		return (MSG_SIG_ABRT);
	if (code == SIGSEGV)
		return (MSG_SEG_ERR);
	if (code == SIGALRM)
		return (MSG_TIME_ERR);
	if (code == SIGFPE)
		return (MSG_FPE_ERR);
	return (MSG_UNKNOWN);
}

int				launch_tests(t_unit_test **ptr)
{
	int			i;
	int			test_ret;
	int			result;
	t_unit_test	*testlist;

	i = 0;
	result = 0;
	testlist = NULL;
	if (*ptr)
		testlist = *ptr;
	while (testlist)
	{
		// printf("    %s : ", testlist->name);
		fflush(stdout);
		test_ret = fork_test(testlist->func);
		if (test_ret == 1)
			result++;
		printf("%s ", test_result_string(test_ret));
		i++;
		testlist = testlist->next;
	}
	//printf("    %d/%d tests passed\n", result, i);
	free_testlist(ptr);
	return (result);
}
