/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/26 17:11:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "structs.h"
#include "rt_math.h"

/// @brief 한 픽셀에 대한 색상 정보
/// @param t Transparency 투명도, 0 불투명 ~ 255 투명함
/// @param r Red
/// @param g Green
/// @param b Blue
/// @return
static int	create_trgb(unsigned char t, unsigned char r, unsigned char g, \
unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

/*
* transform_screen_to_world
* 화면 비율에 맞게 x,y축 길이 조정 + z축 생성
*/
// static t_vec3	transform_screen_to_world(t_window *win, t_vec2 screen)
// {
// 	const double	x_scale = 2.0 / win->width;
// 	const double	y_scale = 2.0 / win->height;
// 	const double	aspect = (double)(win->width) / (double)(win->height);

// 	// TODO scale 적용 안됨.
// 	// 3차원 공간으로 확장 (z좌표는 0.0)
// 	return (vec3((screen.x * x_scale - 1.0) * aspect, -screen.y * y_scale + 1.0, 0.0));
// }

/*
* transform_screen_to_world (카메라 적용 버전)
* 화면 비율에 맞게 x,y축 길이 조정 + z축 생성
*/
static t_vec3	transform_screen_to_world(t_info *info, t_vec2 screen)
{
	// const double	x_scale = 2.0 / info->win.width;
	// const double	y_scale = 2.0 / info->win.height;
	// const double	aspect = (double)(info->win.width) / (double)(info->win.height);

	// TODO scale 적용 안됨.
	// 3차원 공간으로 확장 (z좌표는 0.0)
	// x : x + camera.x
	// y : y + camera.y
	// z : Distance from camera to monitor
	return (vec3((screen.x - (info->win.width / 2)), -(screen.y) + (info->win.height / 2), info->t_c.length));
}


/// @brief ray가 object의 어디에서 부딪히는지 계산한 hit 구조체를 반환한다.
/// @param ray
/// @param sphere 구체에 대한 정보를 가진 구조체
/// @return
static t_hit	check_ray_collision_sphere(t_ray ray, t_obj *sphere)
{
	const double	b = 2.0 * v_dot(ray.normal, \
	v_minus(ray.orig, sphere->coor));
	const double	c = v_dot(v_minus(ray.orig, sphere->coor), \
	v_minus(ray.orig, sphere->coor)) - pow(sphere->diameter / 2.0, 2.0);
	const double	det = (b * b) - (4.0 * c);
	t_hit			hit;

	hit = get_hit(-1.0, vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0));
	if (det >= 0.0)
	{
		hit.d = min_double((-b - sqrt(det)) / 2.0, (-b + sqrt(det)) / 2.0);
		hit.point = v_sum(ray.orig, v_mul_double(ray.normal, hit.d));
		hit.normal = norm_3d_vec(v_minus(hit.point, sphere->coor));
	}
	return (hit);
}

/// @brief 광선이 물체에 닿으면 그 물체의 색 반환. ray를 쏴서 hit된 부분을 찾고 hit의 유효성을 판단.
/// hit.d < 0 : 광선이 물체에 부딪히지 않는다.
/// hit.d = 0 : 광선이 물체에 한번 부딪힌다.
/// hit.d > 0 : 광선이 물체에 두번 부딪힌다.
/// @param obj 특정 물체
/// @param ray 한 픽셀에 대한
/// @return
// static t_vec3	trace_ray(t_obj *obj, t_ray ray)
// {
// 	t_hit	hit;

// 	if (obj->type == PL)
// 		(void)hit;
// 	else if (obj->type == SP)
// 		hit = check_ray_collision_sphere(ray, obj);
// 	else if (obj->type == CY)
// 		(void)hit;
// 	printf("x, y, z : [%f, %f, %f], hit.d : %f\n", ray.orig.x, ray.orig.y, ray.orig.z, hit.d);
// 	if (hit.d < 0.0)
// 		return (vec3(0.0, 0.0, 0.0));
// 	else
// 	{
// 		// 물체의 깊이
// 		// printf("obj->colors:[%f, %f, %f]\n", obj->colors.x, obj->colors.y, obj->colors.z);
// 		// return (v_mul_double(obj->colors, hit.d));
// 		// TODO 각 변수는 상황에 맞게 변경되어야 함.
// 		obj->amb = vec3(1.0, 0.0, 0.0);
// 		obj->diff = vec3(1.0, 0.0, 0.0);
// 		obj->spec = vec3(1.0, 1.0, 1.0);
// 		obj->ks = 1.0f;
// 		obj->alpha = 1.0f;

// 		t_vec3 light = vec3(0.0, 0.0, -1.0); // 화면 뒷쪽
// 		// Diffuse
// 		const t_vec3 dirToLight = norm_3d_vec(v_minus(light, hit.point));
// 		const double diff = max_double(v_dot(hit.normal, dirToLight), 0.0);
// 		// return (v_mul_double(obj->diff, diff));

// 		// Specular
// 		const t_vec3 reflectDir = v_minus_double(v_mul_double(hit.normal, 2.0 * v_dot(hit.normal, dirToLight)), dirToLight.x, dirToLight.y, dirToLight.z);
// 		// const float specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), obj->alpha);
// 		const double specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), 1.0);
// 		// return (v_mul_double(v_mul_double(obj->spec, specular), obj->ks));

// 		// Diffuse + Specular
// 		// return sphere->amb + sphere->diff * diff + sphere->spec * specular * sphere->ks;
// 		return (v_mul_double(v_sum(v_sum(v_mul_double(obj->diff, diff), obj->amb), v_mul_double(v_mul_double(obj->spec, specular), obj->ks)), 255.0));
// 	}
// }

static t_vec3	trace_ray(t_list *objs, t_ray ray)
{
	t_obj	*obj;
	t_hit	hit;
	double	closest;
	t_hit	closest_hit;

	closest = 100000;
	while (objs)
	{
		obj = (t_obj *)(objs->content);
		printf("obj->type : %d\n", obj->type);
		if (obj->type == PL)
			(void)hit;
		else if (obj->type == SP)
			hit = check_ray_collision_sphere(ray, obj);
		else if (obj->type == CY)
			(void)hit;
		if (closest > hit.d)
		{
			closest_hit.d = hit.d;
			closest_hit.normal = hit.normal;
			closest_hit.point = hit.point;
		}
		// printf("x, y, z : [%f, %f, %f], hit.d : %f\n", ray.orig.x, ray.orig.y, ray.orig.z, hit.d);
		objs = objs->next;
	}
	hit = closest_hit;
	if (hit.d >= 0.0)
	{
		// 물체의 깊이
		// printf("obj->colors:[%f, %f, %f]\n", obj->colors.x, obj->colors.y, obj->colors.z);
		// return (v_mul_double(obj->colors, hit.d));
		// TODO 각 변수는 상황에 맞게 변경되어야 함.
		obj->amb = vec3(1.0, 0.0, 0.0);
		obj->diff = vec3(1.0, 0.0, 0.0);
		obj->spec = vec3(1.0, 1.0, 1.0);
		obj->ks = 1.0f;
		obj->alpha = 1.0f;

		t_vec3 light = vec3(0.0, 0.0, -1.0); // 화면 뒷쪽
		// Diffuse
		const t_vec3 dirToLight = norm_3d_vec(v_minus(light, hit.point));
		const double diff = max_double(v_dot(hit.normal, dirToLight), 0.0);
		// return (v_mul_double(obj->diff, diff));

		// Specular
		const t_vec3 reflectDir = v_minus_double(v_mul_double(hit.normal, 2.0 * v_dot(hit.normal, dirToLight)), dirToLight.x, dirToLight.y, dirToLight.z);
		// const float specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), obj->alpha);
		const double specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), 1.0);
		// return (v_mul_double(v_mul_double(obj->spec, specular), obj->ks));

		// Diffuse + Specular
		// return sphere->amb + sphere->diff * diff + sphere->spec * specular * sphere->ks;
		return (v_mul_double(v_sum(v_sum(v_mul_double(obj->diff, diff), obj->amb), v_mul_double(v_mul_double(obj->spec, specular), obj->ks)), 255.0));
	}
	return (vec3(0.0, 0.0, 0.0));
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

	// 카메라 시점으로 결합하려면 transform_screen_to_world에서 카메라로 시점을 바꿔야할것같다.
	// 살짝 이런느낌 (x, y, z)이면 카메라 (50, 50, 0)을 적용해서 (50 + x, 50 + y, 0 + z)로 적용해야하는것이 아닐까..
	// pixel_pos_world = transform_screen_to_world(&info->win, vec2(x, y));
	// 그렇다면 이렇게 넣어볼 수 있겠다.
	// printf("coor:[%f, %f, %f], x, y : [%d, %d]", info->t_c.coor.x, info->t_c.coor.y, info->t_c.coor.z, x, y);
	pixel_pos_world = transform_screen_to_world(info, vec2(x, y));
	// printf(", pixel:[%f, %f, %f], ", pixel_pos_world.x, pixel_pos_world.y, pixel_pos_world.z);
	// pixel_pos_world = vec3(x, y, 0.0); // 시작하는 지점

	// Orthographic projection (정투영) vs perspective projection (원근투영)
	// 지금은 정투영. 원근투영으로 해야 원근법이 적용됨
	// ray_dir = vec3(0.0, 0.0, 1.0); // 향하는 방향 지점
	// ray_dir도 카메라의 시점에 맞게 조정할 수 있다.
	// ray_dir = norm_3d_vec(info->t_c.normal);
	ray_dir = norm_3d_vec(v_minus(pixel_pos_world, info->t_c.coor)); // 카메라에 모니터를 보는 각도가 적용된 광선
	// printf("ray_dir : [%f, %f, %f] ", ray_dir.x, ray_dir.y, ray_dir.z);
	pixel_pos_world.x = info->t_c.coor.x; //캠정보
	pixel_pos_world.y = info->t_c.coor.y;
	pixel_pos_world.z = info->t_c.coor.z;
	pixel_ray = get_ray(pixel_pos_world, ray_dir);
	// TODO 어떤 물체를 보내야 하나? 카메라와 가장 가까운 물체?
	// color = clamp_3d(trace_ray(info->objs->content, pixel_ray), 0.0, 255.0);
	color = clamp_3d(trace_ray(info->objs, pixel_ray), 0.0, 255.0);
	return (create_trgb(0, color.x, color.y, color.z));
}
