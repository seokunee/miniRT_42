/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:17 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/04 17:18:08 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"
#include "window.h"

t_hit	check_ray_collision_sphere(t_ray ray, t_obj *sphere)
{
	const double	b = v_dot(ray.normal, \
	v_minus(ray.orig, sphere->coor));
	const double	c = v_dot(v_minus(ray.orig, sphere->coor), \
	v_minus(ray.orig, sphere->coor)) - pow(sphere->diameter / 2.0, 2.0);
	const double	det = (b * b) - (c);
	t_hit			hit;

	hit = get_hit(-1.0, vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0));
	if (det >= 0.0)
	{
		hit.d = min_double((-b - sqrt(det)), (-b + sqrt(det)));
		hit.point = v_sum(ray.orig, v_mul_double(ray.normal, hit.d));
		hit.normal = norm_3d_vec(v_minus(hit.point, sphere->coor));
		if (sphere->texture.type == CHECK)
			checker(sphere, hit);
		else if (sphere->texture.type == DIFFUSE)
			get_texture_color(sphere, ray, &hit);
	}
	return (hit);
}

static t_vec2	plane_map(const t_vec3 hit, const t_vec3 normal)
{
	double	u;
	double	v;

	if (normal.y == 1)
	{
		u = hit.x - floor(hit.x);
		v = hit.z - floor(hit.z);
		return (vec2(u, v));
	}
	u = hit.x - floor(hit.x);
	v = hit.y - floor(hit.y);
	return (vec2(u, v));
}

t_hit	check_ray_collision_plane(t_ray ray, t_obj *plane)
{
	const double	denom = v_dot(ray.normal, plane->normal);
	double			numrator;
	double			root;
	t_hit			hit;

	hit = get_hit(-1.0, vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0));
	if (fabs(denom) < 0.001)
		return (hit);
	numrator = v_dot(v_minus(plane->coor, ray.orig), plane->normal);
	root = numrator / denom;
	if (root < 0.001 || root > 10000)
		return (hit);
	hit.d = root;
	hit.point = ray_at(ray, root);
	hit.normal = plane->normal;
	if (v_dot(ray.normal, hit.normal) >= 0)
		hit.normal = v_mul_double(hit.normal, -1);
	if (plane->texture.type == CHECK)
		plane->colors = uv_pattern_at(vec2(2, 2), \
		plane_map(hit.point, hit.normal));
	return (hit);
}
