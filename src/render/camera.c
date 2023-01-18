/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:55:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 09:53:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/camera.h"

t_cam_setting	*cam_setting(t_oneweek *one)
{
	
}

t_cam	*create_cam_default(t_oneweek *one)
{
	t_cam	*cam;
	t_vec3	*lookat;
	t_vec3	*vup;
	const float	vfov = 40;
	const float foc_dst = 10;

	lookat = create_3d_vec_input_same_value(0.0f);
	vup = create_3d_vec(0.0f, 1.0f, 0.0f);
	cam = ft_malloc(sizeof(t_cam));
	cam->origin = create_3d_vec(0.0f, 0.0f, -1.0f);
	cam->w = unit_vector(v_sub(cam->origin, lookat));
	cam->u = unit_vector(v_cross(vup, w));
	cam->v = v_cross(w, u);
	cam->horizontal = v_float_mul(cam->u, foc_dst * one->image->aspect * 2.0f * tanf(degrees_to_radians_float(vfov) / 2));
	cam->vertical = v_float_mul(cam->v, foc_dst * 2.0f * tanf(degrees_to_radians_float(vfov) / 2)); 
	cam->lower_left_corner = v_sub(v_sub(cam->origin, v_mul(cam->horizontal, 0.5f)), v_mul(cam->vertical, 0.5f), v_float_mul(cam->w, foc_dst));
	cam->lens_radius = 0;
	cam->time0 = 0;
	cam->time1 = 0;
}