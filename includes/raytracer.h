/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:14:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 09:53:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "minirt.h"
// #include "../src/libft/include/libft.h"
// #include "rt_math.h"

typedef struct s_raytracer
{
	int		width;
	int 	height;
	struct s_vec3	*light;

	// temp variables. 다른곳에서 정의될 수 있음.
	t_list	*object;
	int		num_of_objs;
	t_vec3	*color;
	t_vec3	*phong_color;
}	t_raytracer;

/*
* Ray
* start: Start position of the ray.
* dir: Direction of the ray.
*/
typedef struct s_ray
{
	struct	s_vec3	*start;
	struct	s_vec3	*dir;
}	t_ray;

/*
* Hit
* d: Distance from start of ray to crash point.
* point: Position vector of crash.
* normal: Vertical vector of surface from crash point.
* uv: Coordinates of texture.
*/
typedef struct s_hit
{
	float	d;
	struct	s_vec3	*point;
	struct	s_vec3	*normal;
	struct	s_vec2	*uv;

	t_list			*obj;
}	t_hit;

/*
* Triangle
*/
typedef struct s_tri
{
	struct	s_vec3	*v0;
	struct	s_vec3	*v1;
	struct	s_vec3	*v2;
	struct	s_vec2	*uv0;
	struct	s_vec2	*uv1;
	struct	s_vec2	*uv2;
}	t_tri;

/*
* ray_tracer.c
*/
t_vec3	*transform_screen_to_world(t_info **info, t_vec2 *screen);
t_hit	*find_closest_collision(t_info **info, t_ray *ray);
t_vec3	*trace_ray(t_info **info, t_ray *ray, const int recurse_level);

/*
* sphere.c
*/
t_hit	*check_ray_collision_sphere(t_ray *ray, t_objs *sphere);



#endif
