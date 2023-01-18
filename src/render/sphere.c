/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:02:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 09:50:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_hit	*check_ray_collision_sphere(t_ray *ray, t_objs *sphere)
{
	t_hit	*hit;
	float	b;
	float	c;
	float	det;

	hit = ft_malloc(sizeof(t_hit));
	hit->d = 1.0f;
	hit->point = create_3d_vec_input_same_value(0.0f);
	hit->normal = create_3d_vec_input_same_value(0.0f);
	b = 2.0f * v_dot(ray->dir, v_sub(ray->start, sphere->coor));
	c = v_dot(v_sub(ray->start, sphere->coor), \
		v_sub(ray->start, sphere->coor)) - powf((sphere->diameter / 2), 2.0f);
	det = (b * b) - (4.0f * c);
	if (det >= 0.0f)
	{
		hit->d = min_float((-b - sqrtf(det)) / 2.0f, (-b + sqrtf(det)) / 2.0f);
		hit->point = v_sum(ray->start, v_mul(ray->dir, hit->d));
		hit->normal = norm_3d_vec(v_sub(hit->point, sphere->coor));
	}
	return (hit);
}
