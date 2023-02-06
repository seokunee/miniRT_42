/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:17 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/04 17:18:08:07 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"
#include "window.h"

#define BLACK 0
#define WHITE 1

t_vec3	uv_pattern_at(t_vec4 checkers, double u, double v) // 체커보드용
{
	const double	u2 = floor(u * checkers.x1);
	const double	v2 = floor(v * checkers.x1);
	int i = u2 + v2;

	if (i % 2 == 0)
		return (vec3(0,0,0));
	else
		return (vec3(255, 255, 255));
}

double	spherical_map_u(t_hit hit)
{
	double	theta = atan2(hit.normal.x, hit.normal.z);
	t_vec3	vec = v_change_minus(hit.normal);
	double	radius = v_len(vec);
	double	phi = acos(hit.normal.y / radius);
	double	raw_u = theta / (2 * PI);
	double	u = 1 - (raw_u + 0.5);
	return (u);
}

double	spherical_map_v(t_hit hit)
{
	double	theta = atan2(hit.normal.x, hit.normal.z);
	t_vec3	vec = v_change_minus(hit.normal);
	double	radius = v_len(vec);
	double	phi = acos(hit.normal.y / radius);
	double	raw_u = theta / (2 * PI);
	double	v = 1 - (phi / PI);
	return (v);
}

void	checker(t_obj *sphere, t_hit hit)
{
	t_vec4 checkers = vec4(8, 2, BLACK, WHITE);
	t_vec3 d = v_change_minus(hit.normal);
	double u = spherical_map_u(hit);
	double v = spherical_map_v(hit);
	t_vec3 color = uv_pattern_at(checkers, u, v);
	sphere->colors = color;
}

/// @brief object의 color를 texture color로 바꿀 수 있다..
/// @param obj 바꾸고 싶은 object
/// @param hit obj에 부딪힌 hit
/// @return

void	get_texture_color(t_obj *obj, t_ray ray, t_hit *hit)
{
	t_vec3 d = v_change_minus(hit->normal);
	double u = spherical_map_u(*hit);
	double v = spherical_map_v(*hit);
	// printf("be obj->colors %f %f %f \n", obj->colors.x, obj->colors.y, obj->colors.z);
	obj->colors = get_texture_image_color(&obj->texture, vec2(u, v));
	// printf("af obj->colors %f %f %f \n", obj->colors.x, obj->colors.y, obj->colors.z);

	if (obj->texture_nomal.type == NORMAL)
		copy_vector_value(&hit->normal, sample_normal_map(&obj->texture_nomal, vec2(u, v), hit, v_cross(ray.normal, hit->normal)));
}

/// @brief ray가 sphere의 어디에서 부딪히는지 계산한 hit 구조체를 반환한다.
/// @param ray
/// @param sphere 구체에 대한 정보를 가진 구조체
/// @return
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
	return (hit);
}
