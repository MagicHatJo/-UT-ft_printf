/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:39:59 by jochang           #+#    #+#             */
/*   Updated: 2019/05/19 18:35:45 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_unit_test.h"

int		main(void)
{
	int		num_pass;

	num_pass = 0;
	main_header();
	if (BASIC_ON)
	{
		basic_header();
		num_pass += test_percent();		printf("\n");
		num_pass += test_d();			printf("\n");
		num_pass += test_i();			printf("\n");
		num_pass += test_u();			printf("\n");
		num_pass += test_x();			printf("\n");
		num_pass += test_ux();			printf("\n");
		num_pass += test_o();			printf("\n");
		num_pass += test_s();			printf("\n");
		num_pass += test_c();			printf("\n");
		num_pass += test_p();			printf("\n");
		num_pass += test_n();			printf("\n");
	}
	if (EXTENDED_ON)
	{
		extended_header();
		num_pass += test_f();			printf("\n");
		num_pass += test_uf();			printf("\n");
		num_pass += test_e();			printf("\n");
		num_pass += test_ue();			printf("\n");
		num_pass += test_g();			printf("\n");
		num_pass += test_ug();			printf("\n");
		num_pass += test_a();			printf("\n");
		num_pass += test_ua();			printf("\n");
	}
	if (FLAGS_ON)
	{
		flags_header();
		num_pass += test_minus();		printf("\n");
		num_pass += test_plus();		printf("\n");
		num_pass += test_space();		printf("\n");
		num_pass += test_zero();		printf("\n");
		num_pass += test_sharp();		printf("\n");
		num_pass += test_width();		printf("\n");
		num_pass += test_precision();	printf("\n");
		num_pass += test_length();		printf("\n");
	}
	if (MIX_ON)
	{
		mix_header();
		num_pass += test_mix();			printf("\n");
	}
	if (BONUS_ON)
	{
		bonus_header();
		num_pass += test_star();		printf("\n");
		//b
		//etc?
	}
	if (LEAKS_ON)
	{
		leaks_header();
		system("leaks ft_printf_unit_test | grep \"leaks for\"");
	}
	if (num_pass >= (BASIC_ON * BASIC_COUNT) +
					(EXTENDED_ON * EXTENDED_COUNT) +
					(FLAGS_ON * FLAGS_COUNT) +
					(MIX_ON * MIX_COUNT) +
					(BONUS_ON * BONUS_COUNT))
		all_pass();
	return (0);
}
