/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:01:32 by jochang           #+#    #+#             */
/*   Updated: 2019/05/19 21:01:33 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_unit_test.h"

bool	capture_init(void)
{
	g_stdout_fd_copy = dup(STDOUT_FILENO);
	if (pipe(g_pipe_fds) == -1)
	{
		close(g_stdout_fd_copy);
		return (false);
	}
	if (dup2(g_pipe_fds[1], STDOUT_FILENO) == -1)
	{
		close(g_stdout_fd_copy);
		close(g_pipe_fds[0]);
		close(g_pipe_fds[1]);
		return (false);
	}
	return (true);
}

void	capture_get(char *buf, size_t n)
{
	fflush(stdout);
	memset(buf, 0, n);
	read(g_pipe_fds[0], buf, 4095);
}

void	capture_close(void)
{
	close(g_pipe_fds[1]);
	close(g_pipe_fds[0]);
	dup2(g_stdout_fd_copy, STDOUT_FILENO);
	close(g_stdout_fd_copy);
}
