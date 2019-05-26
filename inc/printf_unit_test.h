/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unit_test.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:40:32 by jochang           #+#    #+#             */
/*   Updated: 2019/05/19 19:01:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UNIT_TEST_H
# define PRINTF_UNIT_TEST_H

# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "ft_printf.h"
# include "libunit.h"

# define BASIC_ON		1
# define BASIC_COUNT	99
# define EXTENDED_ON	1
# define EXTENDED_COUNT	107
# define FLAGS_ON		1
# define FLAGS_COUNT	55
# define MIX_ON			1
# define MIX_COUNT		2
# define BONUS_ON		1
# define BONUS_COUNT	5
# define LEAKS_ON		1

# define MAX_PASS		1
# define BUF_SIZE		1024

/*
** Color
*/

# define C_DEFAULT		"\033[0m"

# define C_RED			"\033[31m"
# define C_GREEN		"\033[32m"
# define C_BROWN		"\033[33m"
# define C_BLUE			"\033[34m"
# define C_PURPLE		"\033[35m"
# define C_CYAN			"\033[36m"
# define C_LIGHTGRAY	"\033[37m"

# define C_YELLOW		"\033[1;33m"
# define C_BOLDBLUE		"\033[1;36m"

/*
** Globals
*/
char	g_char;
char	*g_str;
int		g_stdout_fd_copy;
int		g_pipe_fds[2];

/*
** ft_printf
*/
int		ft_printf(char *s, ...);

/*
** Headers
*/
void	main_header(void);
void	basic_header(void);
void	extended_header(void);
void	flags_header(void);
void	mix_header(void);
void	bonus_header(void);
void	leaks_header(void);
void	all_pass(void);

/*
** Capture
*/
bool	capture_init(void);
void	capture_get(char *buf, size_t n);
void	capture_close(void);

/*
** Basic
*/
int		test_percent(void);
int		test_d(void);
int		test_i(void);
int		test_u(void);
int		test_x(void);
int		test_ux(void);
int		test_o(void);
int		test_s(void);
int		test_c(void);
int		test_p(void);
int		test_n(void);

/*
** Extended
*/
int		test_f(void);
int		test_uf(void);
int		test_e(void);
int		test_ue(void);
int		test_g(void);
int		test_ug(void);
int		test_a(void);
int		test_ua(void);

/*
** Flags
*/
int		test_minus(void);
int		test_plus(void);
int		test_space(void);
int		test_zero(void);
int		test_sharp(void);
int		test_width(void);
int		test_precision(void);
int		test_length(void);

/*
** Mix
*/
int		test_mix(void);

/*
** Bonus
*/
int		test_star(void);

#endif
