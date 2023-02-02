/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 18:55:01 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "structs.h"
#include "rt_math.h"
#include "window.h"

bool	in_shadow(t_list *objs, t_ray light_ray)
{
	t_hit	closest_hit;
	t_obj	*closest_obj;

	get_closest_hit_obj(objs, &closest_hit, light_ray, &closest_obj);
	if (closest_hit.d >= 0.0)
		return (true);
	return (false);
}

t_color3	get_specular(t_info *info, t_hit *hit, t_l *light, t_vec3 light_dir)
{
	double			spec;
	t_color3		specular;
	const t_vec3	reflect = v_minus(v_mul_double(v_mul_double(hit->normal, \
	v_dot(hit->normal, light_dir)), 2), light_dir);
	const t_vec3	view_dir = vunit(v_mul_double(info->ray.normal, -1));

	spec = pow(fmax(v_dot(view_dir, reflect), 0.0), 2);
	specular = v_mul_double(v_mul_double(light->colors, 1.0f), spec);
	return (specular);
}

t_color3	point_light_get(t_info *info, \
t_hit *hit, t_l *light, t_obj *closest_obj)
{
	const t_vec3	light_dir = vunit(v_minus(light->coor, hit->point));
	t_color3		diffuse;
	t_ray			light_ray;
	double			kd;

	light_ray = get_ray(\
		v_sum(hit->point, v_mul_double(hit->normal, 0.001)), light_dir);
	if (in_shadow(info->objs, light_ray))
		return (black_v3());
	kd = fmax(v_dot(hit->normal, light_dir), 0.0);
	diffuse = v_divide(light->colors, 255.0);
	diffuse = v_mul_double(diffuse, light->light_brightness_ratio);
	diffuse = v_mul_double(diffuse, kd);
	diffuse = v_mul(diffuse, closest_obj->colors);
	diffuse = v_sum(diffuse, get_specular(info, hit, light, light_dir));
	return (diffuse);
}
