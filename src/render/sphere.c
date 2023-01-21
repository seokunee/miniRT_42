/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:02:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/22 00:15:21 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"
#include "ray.h"
#include "hit.h"
#include "raytracer.h"

t_hit	check_ray_collision_sphere(t_ray ray, t_objs *sphere)
{
	t_hit	hit;
	float	b;
	float	c;
	float	det;

	hit.d = 1.0f;
	hit.point = vec3(0.0, 0.0, 0.0);
	hit.normal = vec3(0.0, 0.0, 0.0);
	b = 2.0f * v_dot(ray.dir, v_minus(ray.orig, sphere->coor));
	c = v_dot(v_minus(ray.orig, sphere->coor), \
		v_minus(ray.orig, sphere->coor)) - powf((sphere->diameter / 2), 2.0f);
	det = (b * b) - (4.0f * c);
	printf("b, c, det : [%f, %f, %f]\n", b, c, det);
	if (det >= 0.0f)
	{
		hit.d = min_float((-b - sqrtf(det)) / 2.0f, (-b + sqrtf(det)) / 2.0f);
		hit.point = v_sum(ray.orig, v_mul_double(ray.dir, hit.d));
		hit.normal = norm_3d_vec(v_minus(hit.point, sphere->coor));
	}
	return (hit);
}
