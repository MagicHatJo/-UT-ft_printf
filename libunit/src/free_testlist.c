/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_testlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:07:25 by jochang           #+#    #+#             */
/*   Updated: 2019/05/19 18:07:26 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	free_testlist(t_unit_test **ptr)
{
	t_unit_test	*tmp;

	if (!ptr || !*ptr)
		return ;
	while (*ptr)
	{
		tmp = *ptr;
		*ptr = (*ptr)->next;
		free(tmp);
	}
}
