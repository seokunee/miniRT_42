/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:52:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 19:18:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "raytracer.h"
#include "rt_math.h"
#include "info.h"

typedef struct s_cam_setting
{
	t_vec3	lookfrom;
	t_vec3	lookat;
	struct s_vec3	vup;
	double	vfov;
	double	aspect_ratio;
	double	aperture;
	double	focus_dist;
	double	time0;
	double	time1;
}	t_cam_setting;

typedef struct s_cam
{
	t_vec3	origin;				//point
	t_vec3	lower_left_corner;		//point
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	double	lens_radius;
	double	time0;		// shutter open
	double	time1;		// shutter close
}	t_cam;

typedef struct s_oneweek
{
	struct s_info	*info;
	struct s_image	*image;
	struct s_cam	cam;

}	t_oneweek;

t_cam_setting	cam_setting(t_oneweek *one);
void	create_cam_default(t_oneweek *one);

#endif
