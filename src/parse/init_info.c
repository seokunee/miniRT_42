/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:48:40 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 18:05:13 by seokchoi         ###   ########.fr       */
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
	info->t_objs = 0;
	if (!info->t_a || !info->t_c || \
		!info->t_l)
		error_exit("Malloc failure.");
	ft_memset(info->t_a, 0, sizeof(t_a));
	ft_memset(info->t_c, 0, sizeof(t_c));
	ft_memset(info->t_l, 0, sizeof(t_l));
}
