/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/27 14:58:17 by chanwjeo         ###   ########.fr       */
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

void	get_closest_hit_obj(\
	t_list *objs, t_hit	*closest_hit, t_ray ray, t_obj **closest_obj)
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
			closest = hit.d;
			closest_hit->d = hit.d;
			closest_hit->normal = hit.normal;
			closest_hit->point = hit.point;
			*closest_obj = obj;
		}
		objs = objs->next;
	}
}

bool	in_shadow(t_list *objs, t_ray light_ray)
{
	t_hit			closest_hit;
	t_obj			*closest_obj;

	get_closest_hit_obj(objs, &closest_hit, light_ray, &closest_obj);
	if (closest_hit.d >= 0.0)
		return (true);
	return (false);
}

t_color3	point_light_get(\
	t_list *objs, t_hit *hit, t_l *light, t_obj *closest_obj)
{
	const t_vec3	light_dir = vunit(v_minus(light->coor, hit->point));
	t_color3		diffuse;
	t_ray			light_ray;
	double			kd;

	light_ray = get_ray(\
		v_sum(hit->point, v_mul_double(hit->normal, 0.001)), light_dir);
	if (in_shadow(objs, light_ray))
		return (color3(0, 0, 0));
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(v_dot(hit->normal, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값. --> 0.몇값이 나옴.
	// fmax 함수는 두 개의 인자 중 큰 값을 리턴한다. 만약 코사인세타가 둔각이 될 경우 음수가 되기에 0을 리턴하도록 한다.
	diffuse = v_divide(light->colors, 255.0);
	diffuse = v_mul_double(diffuse, light->light_brightness_ratio);
	diffuse = v_mul_double(diffuse, kd);
	diffuse = v_mul(diffuse, closest_obj->colors);
	return (diffuse);
}

/// @brief 광선이 물체에 닿으면 그 물체의 색 반환. ray를 쏴서 hit된 부분을 찾고 hit의 유효성을 판단.
/// hit.d < 0 : 광선이 물체에 부딪히지 않는다.
/// hit.d = 0 : 광선이 물체에 한번 부딪힌다.
/// hit.d > 0 : 광선이 물체에 두번 부딪힌다.
/// @param obj 특정 물체
/// @param ray 한 픽셀에 대한
/// @return
static t_vec3	trace_ray(t_info *info, t_list *objs, t_ray ray)
{
	t_hit		closest_hit;
	t_obj		*closest_obj;
	t_color3	ambient_color;
	t_vec3		light_color;
	t_l			*lights;

	get_closest_hit_obj(objs, &closest_hit, ray, &closest_obj);
	if (closest_hit.d >= 0.0)
	{
		light_color = color3(0, 0, 0);
		lights = info->lights;
		while (lights) // 존재하는 모든 광원들에 대한 정반사, 난반사 값을 연결리스트로 돌아가면서 구해준다.
		{
			light_color = v_sum(light_color, point_light_get(objs, &closest_hit, lights, closest_obj)); // light들을 모아준다.
			lights = lights->next;
		}
		ambient_color = v_divide(v_mul_double(info->amb.colors, \
			pow(info->amb.amb_light_ratio, 2)), 255);
		ambient_color = v_mul(ambient_color, closest_obj->colors);
		return (vmin(v_sum(light_color, ambient_color), color3(255, 255, 255)));
	}
	// return (vec3(0, 0,3 0));	// background : black
	return (vec3(255.0, 255.0, 255.0));	// background : white
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
	t_vec3	color;
	t_ray	pixel_ray;

	pixel_pos_world = transform_screen_to_world(info, vec2(x, y));
	ray_dir = norm_3d_vec(v_minus(pixel_pos_world, info->cam.coor)); // 카메라에 모니터를 보는 각도가 적용된 광선
	pixel_ray = get_ray(info->cam.coor, ray_dir);	// info of cam
	color = clamp_3d(trace_ray(info, info->objs, pixel_ray), 0.0, 255.0); // 최소의 거리의 오브젝트에서 나온 hit 정보를 가지고 색을 반환.
	return (create_trgb(0, color.x, color.y, color.z));
}
