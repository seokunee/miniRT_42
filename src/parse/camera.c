/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:03:23 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/24 10:02:16 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include "info.h"

void	camera_set(t_info *info)
{
	t_cam_set	s;

	if (info->t_c.normal.x == 0 && info->t_c.normal.z == 0)
		info->t_c.normal.z = 0.00001;
	s.lookat = v_sum(info->t_c.coor, info->t_c.normal);
	s.vup = vec3(0.0, 1.0, 0.0);
	s.theta = degrees_to_radians_double((double)(info->t_c.fov));
	s.half_width = tan(s.theta / 2);
	s.viewport_width = 2.0 * s.half_width;
	s.viewport_height = s.viewport_width / info->win.aspect_ratio;
	s.w = vunit(v_mul_double(info->t_c.normal, -1));
	s.u = vunit(v_cross(s.vup, s.w));
	s.v = v_cross(s.w, s.u);
	info->t_c.horizontal = v_mul_double(s.u, s.viewport_width);
	info->t_c.vertical = v_mul_double(s.v, s.viewport_height);
	info->t_c.left_bottom = v_minus(v_minus(v_minus(info->t_c.coor,	\
		v_divide(info->t_c.horizontal, 2)), \
		v_divide(info->t_c.vertical, 2)), s.w);
}

void	get_camera(t_info *info, char **s)
{
	if (sec_arr_len(s) != 4)
		error_exit("Wrong camera argument num");
	info->t_c.coor = get_arg_coor(s[1]);
	info->t_c.normal = get_arg_normal(s[2]);
	check_only_num1(s[3], "");
	info->t_c.fov = atoi(s[3]);
	if (check_range(180, info->t_c.fov) == ERR)
		error_exit("Wrong camera fov argument");
}
