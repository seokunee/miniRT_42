/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:10:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 00:15:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_hit	*find_closest_collision(t_ray *ray)
{
	float	closest_d;
	t_hit	*closest_hit;
	t_hit	*tmp_hit
	int		i;

	closest_hit = ft_malloc(sizeof(t_hit));
	closest_d = 2147483647.0f
	i = -1;
	while (++i < ray->num_of_objs)
	{
		tmp_hit = 
		
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