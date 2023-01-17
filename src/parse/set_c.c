/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 21:18:36 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_camera(t_info *info, char **s)
{
	if (sec_arr_len(s) != 4)
		error_exit("wrong argument");
	info->t_c->coor = get_arg_coor(s[1]);
	info->t_c->normal = get_arg_normal(s[2]);
	check_only_num1(s[3], "");
	info->t_c->fov = atoi(s[3]);
	if (check_range(180, info->t_c->fov) == ERR)
		error_exit("wrong argument");
}