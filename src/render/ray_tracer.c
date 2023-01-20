/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:10:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 13:16:37 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "info.h"
#include "rt_math.h"

t_vec3	transform_screen_to_world(t_info *info, t_vec2 screen)
{
	t_vec3	world;

	world = vec3(screen.x * 2.0 / (double)(info->wid) - 1.0 * (double)(info->wid) / (double)(info->hei), 
		);
	// world->x = (screen->x * 2.0f / (float)(*info)->wid - 1.0f) * \
	// 	(float)((*info)->wid) / (float)((*info)->hei);
	world->y = (-(screen->y) * 2.0f / (float)(*info)->hei + 1.0f);
	world->z = 0.0f;
	return (world);
}

t_hit	*find_closest_collision(t_info **info, t_ray *ray)
{
	float	closest_d;
	t_hit	*closest_hit;
	t_hit	*tmp_hit;
	t_objs	*tmp_list;

	closest_hit = (void *)0;
	closest_d = 2147483647.0f;
	tmp_list = (*info)->t_objs;
	while (tmp_list != (void *)0)
	{
		if (tmp_list->type == 2)	// sphere
			tmp_hit = check_ray_collision_sphere(ray, tmp_list);
		if (tmp_hit->d >= 0.0f && tmp_hit->d < closest_d)
		{
			if (closest_hit)
				free(closest_hit); 
			closest_hit = tmp_hit;
		}
		tmp_list = tmp_list->next;
	}
	return (tmp_hit);
}

t_vec3	*trace_ray(t_info **info, t_ray *ray, const int recurse_level)
{
	t_vec3	*dir_to_light;
	t_vec3	*reflect_dir;
	t_hit	*closest;

	closest = find_closest_collision(info, ray);
	if ((*info)->hit->d < 0.0f)
		return (create_3d_vec_i3nput_same_value(0.0f));
	dir_to_light = norm_3d_vec(v_sub((*info)->t_l->coor, closest->point));
	(*info)->diff = max_float(v_dot(closest->normal, dir_to_light), 0.0f);
	reflect_dir = v_mul(v_sub(closest->normal, dir_to_light), v_dot(closest->normal, dir_to_light) * 2.0f);
	(*info)->specular = powf(max_float(v_dot(v_minus(ray->dir), reflect_dir), 0.0f), 10.0f);	// 10.0f : alpha
	return v_sum((*info)->t_a->colors, v_mul(closest->obj., (*info)->diff));
	// return hit.obj->amb + hit.obj->dif * diff + hit.obj->spec * specular;
}

/*
diff
alpha
spec
*/