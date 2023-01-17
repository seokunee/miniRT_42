/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 18:22:27 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_light(t_info *info, char **s)
{
	if (sec_arr_len(s) != 3 && sec_arr_len(s) != 4)
		error_exit("Wrong argument");
	info->t_l->coor = get_arg_coor(s[1]);
	info->t_l->light_brightness_ratio = ft_atof(s[2]);
	if (check_range(1, info->t_l->light_brightness_ratio) == ERR)
		error_exit("Wrong argument");
	if (sec_arr_len(s) == 4)
		info->t_l->colors = get_arg_color(s[3]);
}
