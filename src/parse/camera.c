/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:03:23 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/27 14:13:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"
#include "rt_math.h"

void	get_camera(t_info *info, char **s)
{
	if (sec_arr_len(s) != 4)
		error_exit("Wrong camera argument num");
	info->cam.coor = get_arg_coor(s[1]);
	info->cam.normal = get_arg_normal(s[2]);
	check_only_num1(s[3], "");
	info->cam.fov = atoi(s[3]);
	if (check_range(180, info->cam.fov) == ERR)
		error_exit("Wrong camera fov argument");
}

void	camera_setting(t_info *info)
{
	info->cam.length = info->win.width / (2 * tan(degrees_to_radians_double(info->cam.fov / 2 )));
}
