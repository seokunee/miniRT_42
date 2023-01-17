/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 21:18:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_light(t_info *info, char **s)
{
	if (sec_arr_len(s) != 4)
		error_exit("wrong argument");
	info->t_l->coor = get_arg_coor(s[1]);
	info->t_l->colors = get_arg_color(s[2]);
	info->t_l->light_brightness_ratio = ft_atof(s[3]);
	if (check_range(1, info->t_l->light_brightness_ratio) == ERR)
		error_exit("wrong argument");
}