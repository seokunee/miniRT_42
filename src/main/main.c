/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 09:37:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

void	init_info(t_info *info)
{
	ft_memset(info, 0, sizeof(t_info));
	info->t_a = malloc(sizeof(t_a));
	info->t_c = malloc(sizeof(t_c));
	info->t_l = malloc(sizeof(t_l));
	info->t_pl = malloc(sizeof(t_pl));
	info->t_sp = malloc(sizeof(t_sp));
	info->t_cy = malloc(sizeof(t_cy));
	if (!info->t_a || !info->t_c || !info->t_cy || \
		!info->t_l || !info->t_pl || !info->t_sp)
		error_exit("Malloc failure.");
	ft_memset(info->t_a, 0, sizeof(t_a));
	ft_memset(info->t_c, 0, sizeof(t_c));
	ft_memset(info->t_l, 0, sizeof(t_l));
	ft_memset(info->t_pl, 0, sizeof(t_pl));
	ft_memset(info->t_sp, 0, sizeof(t_sp));
	ft_memset(info->t_cy, 0, sizeof(t_cy));
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		error_exit("Invalid number of arguments. Check it!");
	init_info(&info);
	system("leaks minirt");
	return (0);
}
