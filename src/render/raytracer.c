/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 16:56:10 by chanwjeo         ###   ########.fr       */
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

void	set_closest_hit_obj(t_hit *closest_hit, t_hit hit, t_obj **closest_obj, t_obj *obj)
{
	closest_hit->d = hit.d;
	closest_hit->normal = hit.normal;
	closest_hit->point = hit.point;
	*closest_obj = obj;
}

void	get_closest_hit_obj(\
	t_list *objs, t_hit *closest_hit, t_ray ray, t_obj **closest_obj)
{
	t_hit	hit;
	t_obj	*obj;
	double	closest;

	closest = 100000;
	closest_hit->d = -1;
	while (objs)
	{
		obj = (t_obj *)(objs->content);
		if (obj->type == CY)
			hit = check_ray_collision_cylinder(ray, obj);
		else if (obj->type == SP)
			hit = check_ray_collision_sphere(ray, obj);
		else if (obj->type == PL)
			hit = check_ray_collision_plane(ray, obj);
		if (hit.d >= 0 && closest > hit.d)
		{
			set_closest_hit_obj(closest_hit, hit, closest_obj, obj);
			closest = hit.d;
			// closest_hit->d = hit.d;
			// closest_hit->normal = hit.normal;
			// closest_hit->point = hit.point;
			// *closest_obj = obj;
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
		// 존재하는 모든 광원들에 대한 정반사, 난반사 값을 연결리스트로 돌아가면서 구해준다.
		while (lights)
		{
			// light_color = v_sum(light_color, point_light_get(info->objs, &closest_hit, lights, closest_obj, ray)); // light들을 모아준다.
			light_color = v_sum(light_color, point_light_get(info, &closest_hit, lights, closest_obj));
			lights = lights->next;
		}
		ambient_color = v_divide(v_mul_double(info->amb.colors, \
			pow(info->amb.amb_light_ratio, 2)), 255);
		ambient_color = v_mul(ambient_color, closest_obj->colors);

		return (vmin(v_sum(light_color, ambient_color), white_v3()));
	}
	return (black_v3());
	// return (white_v3());
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
	// t_vec3	eye_pos;

	pixel_pos_world = transform_screen_to_world(info, vec2(x, y));
	// 카메라에서 모니터를 보는 각도를 갖는 광선
	ray_dir = norm_3d_vec(v_minus(pixel_pos_world, info->cam.coor));
	// pixel_ray = get_ray(info->cam.coor, ray_dir);
	info->ray = get_ray(info->cam.coor, ray_dir);
	// 최소의 거리의 오브젝트에서 나온 hit 정보를 가지고 색을 반환.
	return (get_color(trace_ray(info, info->ray)));
}
