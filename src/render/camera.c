/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:55:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 12:55:58 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/camera.h"

t_cam_setting	cam_setting(t_oneweek *one)
{
	t_cam_setting	set;
	const t_info	*info = one->info;

	set.lookfrom = create_3d_vec(info->t_c->coor->x, info->t_c->coor->y, info->t_c->coor->z);
	set.lookat = create_3d_vec_input_same_value(0.0f);
	set.vup = info->t_c->normal;
	set.vfov = info->t_c->fov;
	set.aspect_ratio = info->wid / info->hei;
	set.aperture = 0.1;
	set.focus_dist = 10.0;
	set.time0 = 0;
	set.time1 = 0;
	return (set);
}

t_cam	create_cam_default(t_oneweek *one)
{
	t_cam_setting set;
	t_cam	cam;
	t_vec3	*lookat;

	set = cam_setting(one);
	cam.origin = set.lookfrom;
	cam.w = unit_vector(v_sub(cam.origin, set.lookat));
	cam.u = unit_vector(v_cross(set.vup, cam.w));
	cam.v = v_cross(cam.w, cam.u);
	cam.horizontal = v_float_mul(cam.u, set.focus_dist * set.aspect_ratio * 2.0f * tanf(degrees_to_radians_float(set.vfov) / 2));
	cam.vertical = v_float_mul(cam.v, set.focus_dist * 2.0f * tanf(degrees_to_radians_float(set.vfov) / 2)); 
	cam.lower_left_corner = v_sub(v_sub(cam.origin, v_mul(cam.horizontal, 0.5f)), v_mul(cam.vertical, 0.5f), v_float_mul(cam.w, set.focus_dist));
	cam.lens_radius = 0;
	cam.time0 = set.time0;
	cam.time1 = set.time1;
	return (cam);
}

t_ray	get_ray(t_cam cam, double s, double t)
{
	return (create_ray(cam.origin, v_sub(v_sum(cam.lower_left_corner, \
		v_float_mul(cam.horizontal, s)), cam.origin)), 0);
}

