/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:55:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 12:44:19 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "info.h"

t_cam_setting	cam_setting(t_oneweek *one)
{
	t_cam_setting	set;
	const t_info	*info = one->info;

	set.lookfrom = vec3(info->t_c.coor.x, info->t_c.coor.y, info->t_c.coor.z);
	set.lookat = vec3(0.0, 0.0, 0.0);
	set.vup = vec3(info->t_c.normal.x, info->t_c.normal.y, info->t_c.normal.z); //info->t_c.normal;
	set.vfov = info->t_c.fov;
	set.aspect_ratio = info->wid / info->hei;
	set.aperture = 0.1;
	set.focus_dist = 10.0;
	set.time0 = 0;
	set.time1 = 0;
	return (set);
}

void	create_cam_default(t_oneweek *one)
{
	t_cam_setting set;
	t_cam	cam;

	set = cam_setting(one);
	cam.origin = set.lookfrom;
	cam.w = vunit(v_minus(cam.origin, set.lookat));
	cam.u = vunit(v_cross(set.vup, cam.w));
	cam.v = v_cross(cam.w, cam.u);
	cam.horizontal = v_mul_double(cam.u, set.focus_dist * set.aspect_ratio * 2.0f * tanf(degrees_to_radians_float(set.vfov) / 2));
	cam.vertical = v_mul_double(cam.v, set.focus_dist * 2.0 * tanf(degrees_to_radians_float(set.vfov) / 2)); 
	cam.lower_left_corner = v_minus(v_minus(v_minus(cam.origin, v_mul_double(cam.horizontal, 0.5)), v_mul_double(cam.vertical, 0.5)), v_mul_double(cam.w, set.focus_dist));
	cam.lens_radius = 0;
	cam.time0 = set.time0;
	cam.time1 = set.time1;
	one->cam = cam;
}
