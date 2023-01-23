/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:03:23 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/24 01:11:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include "info.h"

void		camera_set(t_info *info)
{
	t_cam_set	s;
	t_c			cam;

	cam = info->t_c;
	if (cam.normal.x == 0 && cam.normal.z == 0)
		cam.normal.z = 0.00001;
	s.lookat = v_sum(cam.coor, cam.normal);
	s.vup = vec3(0.0, 1.0, 0.0);
	s.theta = deg_to_rad(cam.fov);
	s.half_width = tan(s.theta / 2);
	s.viewport_width = 2.0 * s.half_width;
	s.viewport_height = s.viewport_width / info->aspect_ratio;	// aspect_ratio 해야함
	s.w = vunit(v_mul(cam.normal, -1));
	s.u = vunit(v_cross(s.vup, s.w));
	s.v = v_cross(s.w, s.u);
	cam.horizontal = v_mul_double(s.u, s.viewport_width);
	cam.vertical = v_mul_double(s.v, s.viewport_height);
	cam.left_bottom = vminus(v_minus(v_minus(cam.coor,
			vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), s.w);
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
