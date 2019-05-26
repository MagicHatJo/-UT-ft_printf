/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:01:49 by jochang           #+#    #+#             */
/*   Updated: 2019/05/18 21:01:50 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_unit_test.h"

void	all_pass(void)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		ret;

	if ((fd = open("all_pass.txt", O_RDONLY)) < 0)
		printf("All Tests Pass\n");
	else
	{
		while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		{
			printf("%s", buf);
			bzero(buf, BUF_SIZE);
		}
		printf("\n");
		close(fd);
	}
}
