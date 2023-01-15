/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:14:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 00:06:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

int		intersect_ray_triangle(t_ray *ray, t_tri *tri, t_hit **hit)
{
	t_vec3	*c0;
	t_vec3	*c1;
	t_vec3	*c2;

	(*hit)->normal = normalize_3d_vector(v_cross( \
		v_sub(tri->v1, tri->v0), v_sub(tri->v2, tri->v0)));
	(*hit)->d = (v_dot(tri->v0, (*hit)->normal) - \
		v_dot(ray->start, (*hit)->normal)) / v_dot(ray->dir, (*hit)->normal);
	(*hit)->point = v_sum(ray->start, v_mul(ray->dir, (*hit)->d));
	c0 = v_cross(v_sub((*hit)->point, tri->v2), v_sub(tri->v1, tri->v2));
	c1 = v_cross(v_sub((*hit)->point, tri->v0), v_sub(tri->v2, tri->v0));
	c2 = v_cross(v_sub(tri->v1, tri->v0), v_sub((*hit)->point, tri->v0));
	if (v_dot(v_minus(ray->dir), (*hit)->normal) < 0.0f || abs_float( \
		v_dot(ray->dir, (*hit)->normal)) < 1e-2f || (*hit)->d < 0.0f || \
		v_dot(c0, (*hit)->normal) < 0.0f || v_dot(c1, (*hit)->normal) < 0.0f \
		|| v_dot(c2, (*hit)->normal) < 0.0f)
		return (FALSE);
	(*hit)->uv = v_sum_2d(v_sum_2d(
		v_mul_2d(tri->uv0, v_len(c0) * 0.5f / \
		(v_len(c0) * 0.5f + v_len(c1) * 0.5f + v_len(c2) * 0.5f)), 
		v_mul_2d(tri->uv1, v_len(c1) * 0.5f / \
		(v_len(c0) * 0.5f + v_len(c1) * 0.5f + v_len(c2) * 0.5f))), 
		v_mul_2d(tri->uv2, v_len(c2) * 0.5f / \
		(v_len(c0) * 0.5f + v_len(c1) * 0.5f + v_len(c2) * 0.5f)));
	return (TRUE);
}

t_hit	*check_ray_collision(t_ray *ray, t_tri *tri)
{
	t_hit	*hit;

	hit = ft_malloc(sizeof(t_hit));
	hit->d = 1.0f;
	hit->point = create_3d_vec_input_same_value(0.0f);
	hit->normal = create_3d_vec_input_same_value(0.0f);
	if (intersect_ray_triangle(ray, tri, &hit))
	return (hit);
}

t_hit	*find_closest_collision(t_ray *ray)
{
	float	closest_d;
	t_hit	*closest_hit;
	int		i;

	closest_hit = ft_malloc(sizeof(t_hit));
	closest_d = 2147483647.0
	i = -1;
	while (++i < ray->num_of_objs)
	{

		
	}
	for (int l = 0; l < objects.size(); l++)
	{
		auto hit = objects[l]->CheckRayCollision(ray);

		if (hit.d >= 0.0f)
		{
			if (hit.d < closestD)
			{
				closestD = hit.d;
				closestHit = hit;
				closestHit.obj = objects[l];

				// 텍스춰 좌표
				closestHit.uv = hit.uv;
			}
		}
	}
}