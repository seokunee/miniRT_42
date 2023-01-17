/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:10:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 09:54:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_vec3	*transform_screen_to_world(t_info **info, t_vec2 *screen)
{
	t_vec3	*world;

	world = ft_malloc(sizeof(t_vec3));
	world->x = (screen->x * 2.0f / (float)(*info)->wid - 1.0f) * \
		(float)((*info)->wid) / (float)((*info)->hei);
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
	if ((*info)->hit->d >= 0.0f)
	{
		dir_to_light = norm_3d_vec(v_sub((*info)->t_l->coor, closest->point));
		
	}
}

// vec3 traceRay(Ray &ray)
// {
// 	// Render first hit
// 	const auto hit = FindClosestCollision(ray);

// 	if (hit.d >= 0.0f)
// 	{
// 		// Diffuse
// 		const vec3 dirToLight = glm::normalize(light.pos - hit.point);
// 		const float diff = glm::max(dot(hit.normal, dirToLight), 0.0f);

// 		// Specular
// 		const vec3 reflectDir = 2.0f * dot(hit.normal, dirToLight) * hit.normal - dirToLight;
// 		const float specular = glm::pow(glm::max(glm::dot(-ray.dir, reflectDir), 0.0f), hit.obj->alpha);

// 		return hit.obj->amb + hit.obj->dif * diff + hit.obj->spec * specular;
// 	}

// 	return vec3(0.0f);
// }

// // 임시로 정의해놓음
// t_vec3	*trace_ray(t_info *info, t_ray *ray, const int recurse_level)
// {
// 	t_vec3	*dir_to_light;
// 	t_vec3	*reflect_dir;

// 	if (recurse_level < 0)
// 		return (create_3d_vec_input_same_value(0.0f));
// 	info->hit = find_closest_collision(info, ray);
// 	if (info->hit->d >= 0.0f)
// 	{
// 		if (info->color)
// 			free(info->color);
// 		if (info->phong_color)
// 			free(info->phong_color);
// 		info->color = create_3d_vec_input_same_value(0.0f);
// 		info->phong_color = create_3d_vec_input_same_value(0.0f);
// 		dir_to_light = norm_3d_vec(v_sub(info->t_l->coor, info->hit->point));
// 		info->diff = max_float(v_dot(info->hit->normal, dir_to_light), 0.0f);
// 		reflect_dir = v_sub(v_mul(v_mul(info->hit->normal, 2.0f), v_dot(dir_to_light, info->hit->normal)), dir_to_light);
// 		info->specular = powf(max_float(v_dot(v_minus(ray->dir), reflect_dir), 0.0f), info->hit->obj->alpha);

// 		// 함수 내부에서 free를 해주면 깔끔할듯
// 		if (hit->obj->amb_texture)
// 			rt->phong_color = v_sum(rt->phong_color, v_cross(hit->obj->amb, sample_linear(hit->uv)));
// 		else
// 			rt->phong_color = v_sum(rt->phong_color, hit->obj->amb);
// 		if (hit->obj->dif_texture)
// 			rt->phong_color = v_sum(rt->phong_color, (v_mul(hit->obj->dif, diff)))
		
// 	}
// }
