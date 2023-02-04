/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/04 18:06:34 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "structs.h"
#include "rt_math.h"
#include "window.h"

/*
* transform_screen_to_world (카메라 적용 버전)
@ return : vec3(x, y, z)
* x : x + camera.x
* y : y + camera.y
* z : Distance from camera to monitor
*/
static t_vec3	transform_screen_to_world(t_info *info, t_vec2 screen)
{
	const double	x_scale = screen.x - (info->win.width / 2);
	const double	y_scale = -(screen.y) + (info->win.height / 2);

	return (vec3(x_scale, y_scale, info->cam.length));
}

void	set_closest_hit_obj(t_hit *closest_hit, \
t_hit hit, t_obj **closest_obj, t_obj *obj)
{
	closest_hit->d = hit.d;
	copy_vector_value(&closest_hit->normal, hit.normal);
	copy_vector_value(&closest_hit->point, hit.point);

	// closest_hit->normal = hit.normal;
	// closest_hit->point = hit.point;
	*closest_obj = obj;
}

void copy_hit_value(t_hit *dst, t_hit src)
{
	dst->d = src.d;
	dst->normal.x = src.normal.x;
	dst->normal.y = src.normal.y;
	dst->normal.z = src.normal.z;
	dst->point.x = src.point.x;
	dst->point.y = src.point.y;
	dst->point.z = src.point.z;
}


void	get_closest_hit_obj(t_list *objs, \
t_hit *closest_hit, t_ray ray, t_obj **closest_obj)
{
	t_hit	hit;
	t_obj	*obj;
	double	closest;

	closest = 100000;
	closest_hit->d = -1;
	while (objs)
	{
		obj = (t_obj *)objs->content;
		if (obj->type == CY)
			hit = check_ray_collision_cylinder(ray, obj);
		else if (obj->type == SP)
			copy_hit_value(&hit, check_ray_collision_sphere(ray, obj));
		else if (obj->type == PL)
			hit = check_ray_collision_plane(ray, obj);
		else if (obj->type == CN)
			hit = check_ray_collision_cone(ray, obj);
		if (hit.d >= 0 && closest > hit.d)
		{
			set_closest_hit_obj(closest_hit, hit, closest_obj, obj);
			closest = hit.d;
		}
		objs = objs->next;
	}
}

static t_vec3	trace_ray(t_info *info, t_ray ray)
{
	t_hit		closest_hit;
	t_obj		*closest_obj;
	t_color3	ambient_color;
	t_vec3		light_color;
	t_l			*lights;

	get_closest_hit_obj(info->objs, &closest_hit, ray, &closest_obj);
	if (closest_hit.d >= 0.0)
	{
		light_color = black_v3();
		lights = info->lights;
		while (lights)
		{
			light_color = v_sum(light_color, \
			point_light_get(info, &closest_hit, lights, closest_obj));
			lights = lights->next;
		}
		ambient_color = v_divide(v_mul_double(info->amb.colors, \
			pow(info->amb.amb_light_ratio, 2)), 255);
		ambient_color = v_mul(ambient_color, closest_obj->colors);

		// t_vec3			b_normal_result;
		// t_vec3			g_bitangent_result;
		// t_vec3			r_tangent_result;
		// t_vec3			derivative;
		// t_vec3			result;
		// // tamgent = v_cross(ray.normal, hit->normal)


		// r_tangent_result = v_mul_double(v_cross(ray.normal, closest_hit.normal), derivative.x);
		// g_bitangent_result = v_mul_double(v_cross(closest_hit.normal, v_cross(ray.normal, closest_hit.normal)), derivative.y);
		// b_normal_result = v_mul_double(closest_hit.normal, derivative.z);
		// result = v_sum(b_normal_result, g_bitangent_result);
		// result = v_sum(result, r_tangent_result);

		return (vmin(v_sum(light_color, ambient_color), white_v3()));
	}
	return (black_v3());
}

/// @brief 모니터에 그려질 2차원 (x, y) 좌표를 3차원으로 표현하기 위해서 모니터 비율에 맞춰서 3차원 벡터로 만들어줌.
/// @param info 각종 정보를 가진 구조체
/// @param x for문에서 넘겨받은 width의 x
/// @param y for문에서 넘겨받은 height의 y
/// @return
int	calculate_pixel_color(t_info *info, int x, int y)
{
	t_vec3	pixel_pos_world;
	t_vec3	ray_dir;
	t_ray	pixel_ray;

	pixel_pos_world = transform_screen_to_world(info, vec2(x, y));
	ray_dir = norm_3d_vec(v_minus(pixel_pos_world, info->cam.coor));
	info->ray = get_ray(info->cam.coor, ray_dir);
	return (get_color(trace_ray(info, info->ray)));
}
