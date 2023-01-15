/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:14:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/15 19:52:53 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

int		intersect_ray_triangle(t_ray *ray, t_tri *tri, t_hit **hit)
{
	t_vec3	*c0;
	t_vec3	*c1;
	t_vec3	*c2;

	(*hit)->normal = normalize_3d_vector(vec_cross( \
		vec_sub(tri->v1, tri->v0), vec_sub(tri->v2, tri->v0)));
	(*hit)->d = (vec_dot(tri->v0, (*hit)->normal) - \
		vec_dot(ray->start, (*hit)->normal)) / \
		vec_dot(ray->dir, (*hit)->normal);
	(*hit)->point = vec_sum(ray->start, vec_multiple(ray->dir, (*hit)->d));
	c0 = vec_cross(vec_sub((*hit)->point, tri->v2), vec_sub(tri->v1, tri->v2));
	c1 = vec_cross(vec_sub((*hit)->point, tri->v0), vec_sub(tri->v2, tri->v0));
	c2 = vec_cross(vec_sub(tri->v1, tri->v0), vec_sub((*hit)->point, tri->v0));
	if (vec_dot(vec_minus(ray->dir), (*hit)->normal) < 0.0f || \
		abs_float(vec_dot(ray->dir, (*hit)->normal)) < 1e-2f || \
		(*hit)->d < 0.0f || vec_dot(c0, (*hit)->normal) < 0.0f || \
		vec_dot(c1, (*hit)->normal) < 0.0f || \
		vec_dot(c2, (*hit)->normal) < 0.0f)
		return (FALSE);
	(*hit)->uv = 
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