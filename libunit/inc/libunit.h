/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:44:49 by jochang           #+#    #+#             */
/*   Updated: 2019/05/19 21:50:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>

/*
** Output Messages
*/

# define MSG_OK			"\033[32m[OK]\033[0m"
# define MSG_KO			"\033[31m[KO]\033[0m"
# define MSG_FORK_ERR	"\033[31m[FRKE]\033[0m"
# define MSG_SIG_ABRT	"\033[31m[ABRT]\033[0m"
# define MSG_BUS_ERR	"\033[31m[BUSE]\033[0m"
# define MSG_FPE_ERR	"\033[31m[FPE]\033[0m"
# define MSG_SEG_ERR	"\033[31m[SEGV]\033[0m"
# define MSG_TIME_ERR	"\033[31m[TIME]\033[0m"
# define MSG_UNKNOWN	"\033[1;33m[UNKN]\033[0m"

/*
** Structs
*/

typedef struct	s_unit_test
{
	char				*name;
	int					(*func)(void);
	struct s_unit_test	*next;
}				t_unit_test;

/*
** Functions
*/

void			load_test(t_unit_test **testlist,
							char *test_name, int (*func)(void));
int				launch_tests(t_unit_test **testlist);
void			free_testlist(t_unit_test **ptr);

#endif
