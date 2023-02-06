/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:25:35 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/06 21:09:14 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"
#include "window.h"

#define BLACK 0
#define WHITE 1

// 체커보드용
t_vec3	uv_pattern_at(t_vec2 checkers, t_vec2 uv)
{
	const double	u2 = floor(uv.x * checkers.x);
	const double	v2 = floor(uv.y * checkers.y);
	int				i;

	i = u2 + v2;
	if (i % 2 == 0)
		return (black_v3());
	else
		return (white_v3());
}

t_vec2	spherical_map(t_vec3 p)
{
	const double	theta = atan2(p.x, p.z);
	const t_vec3	vec = vec3(p.x, p.y, p.z);
	const double	radius = v_len(vec);
	t_vec2			uv;

	uv.x = 1.0 - ((theta / (2 * PI)) + 0.5);
	uv.y = 1.0 - (acos(p.y / radius)) / PI;
	return (uv);
}

void	checker(t_obj *sphere, t_hit hit)
{
	const t_vec2	checkers = vec2(4, 4);
	const t_vec2	uv = spherical_map(hit.normal);

	sphere->colors = uv_pattern_at(checkers, uv);
}

/// @brief object의 color를 texture color로 바꿀 수 있다..
/// @param obj 바꾸고 싶은 object
/// @param hit obj에 부딪힌 hit
/// @return
void	get_texture_color(t_obj *obj, t_ray ray, t_hit *hit)
{
	const t_vec2	uv = spherical_map(hit->normal);

	obj->colors = get_texture_image_color(&obj->texture, uv);
	if (obj->texture_nomal.type == NORMAL)
		hit->normal = sample_normal_map(&obj->texture_nomal, uv, hit, v_cross(ray.normal, hit->normal));
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
