/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:48:40 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 10:20:15 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/info.h"

/*
* struct info malloc and initializaion
*/
void	init_info(t_info *info)
{
	ft_memset(info, 0, sizeof(t_info));
	info->t_a = malloc(sizeof(t_a));
	info->t_c = malloc(sizeof(t_c));
	info->t_l = malloc(sizeof(t_l));
	info->t_objs = malloc(sizeof(t_objs));
	// info->t_pl = malloc(sizeof(t_pl));
	// info->t_sp = malloc(sizeof(t_sp));
	// info->t_cy = malloc(sizeof(t_cy));
	if (!info->t_a || !info->t_c || !info->t_objs || \
		!info->t_l)
		error_exit("Malloc failure.");
	ft_memset(info->t_a, 0, sizeof(t_a));
	ft_memset(info->t_c, 0, sizeof(t_c));
	ft_memset(info->t_l, 0, sizeof(t_l));
	ft_memset(info->t_objs, 0, sizeof(t_objs));
	// ft_memset(info->t_pl, 0, sizeof(t_pl));
	// ft_memset(info->t_sp, 0, sizeof(t_sp));
	// ft_memset(info->t_cy, 0, sizeof(t_cy));
}
