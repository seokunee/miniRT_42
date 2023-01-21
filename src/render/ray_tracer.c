/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:10:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/22 00:15:21 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "raytracer.h"
#include "info.h"
#include "hit.h"
#include "rt_math.h"
#include "ray.h"

t_vec3	transform_screen_to_world(t_info *info, t_vec2 screen)
{
	t_vec3	world;

	world = vec3(screen.x * 2.0 / (double)(info->wid) - 1.0 * (double)(info->wid) / (double)(info->hei), 
		-(screen.y) * 2.0 / (double)(info->hei) + 1.0, 0.0);
	return (world);
}

t_hit	find_closest_collision(t_info *info, t_ray ray)
{
	float	closest_d;
	t_hit	closest_hit;
	t_hit	tmp_hit;
	t_list	*tmp_list;
	t_objs	*tmp_obj;

	closest_d = 2147483647.0f;
	tmp_list = info->t_objs;
	while (tmp_list != 0)
	{
		tmp_obj = tmp_list->content;
		if (tmp_obj->type == SP)	// sphere
			tmp_hit = check_ray_collision_sphere(ray, tmp_obj);
		if (tmp_hit.d >= 0.0f && tmp_hit.d < closest_d)
		{
			closest_d = tmp_hit.d;
			closest_hit.d = tmp_hit.d;
			closest_hit.normal = vec3(tmp_hit.normal.x, tmp_hit.normal.y, tmp_hit.normal.z);
			closest_hit.point = vec3(tmp_hit.point.x, tmp_hit.point.y, tmp_hit.point.z);
			printf("closest_hit.d : %f, clost_hit.normal : [%f, %f, %f], clost_hit.point : [%f, %f, %f]\n", closest_hit.d, closest_hit.normal.x, closest_hit.normal.y, closest_hit.normal.z, closest_hit.point.x, closest_hit.point.y, closest_hit.point.z);
		}
		tmp_list = tmp_list->next;
		tmp_hit.d = -1.0f;
	}
	return (closest_hit);
}

t_vec3	trace_ray(t_info *info, t_ray ray, const int recurse_level)
{
	t_vec3	dir_to_light;
	t_vec3	reflect_dir;
	t_hit	closest;

	(void)recurse_level;
	closest = find_closest_collision(info, ray);
	if (info->hit->d < 0.0f)
		return (vec3(0.0, 0.0, 0.0));
	dir_to_light = norm_3d_vec(v_minus(info->t_l->coor, closest.point));
	info->diff = max_float(v_dot(closest.normal, dir_to_light), 0.0f);
	reflect_dir = v_mul_double(v_minus(closest.normal, dir_to_light), v_dot(closest.normal, dir_to_light) * 2.0f);
	info->specular = powf(max_float(v_dot(v_change_minus(ray.dir), reflect_dir), 0.0f), 10.0f);	// 10.0f : alpha
	return (reflect_dir);
	// return hit.obj->amb + hit.obj->dif * diff + hit.obj->spec * specular;
}

/*
diff
alpha
spec
*/