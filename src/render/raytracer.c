/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/27 14:14:54 by chanwjeo         ###   ########.fr       */
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
* transform_screen_to_world (카메라 적용 버전)
*
*/
static t_vec3	transform_screen_to_world(t_info *info, t_vec2 screen)
{
	const double	x_scale = screen.x - (info->win.width / 2);
	const double	y_scale = -(screen.y) + (info->win.height / 2);

	// 3차원 공간으로 확장 (z좌표는 0.0)
	// x : x + camera.x
	// y : y + camera.y
	// z : Distance from camera to monitor
	return (vec3(x_scale, y_scale, info->cam.length));
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

t_color3	point_light_get(t_hit *hit, t_l *light, t_obj *closest_obj)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd; // diffuse의 강도
	double		light_len;

	light_dir = v_minus(light->coor, hit->point); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	light_len = v_len(light_dir);
	light_dir = vunit(light_dir);
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(v_dot(hit->normal, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	// fmax 함수는 두 개의 인자 중 큰 값을 리턴한다. 만약 코사인세타가 둔각이 될 경우 음수가 되기에 0을 리턴하도록 한다.
	diffuse = v_divide(light->colors, 255.0); // 255 나눈 이유는 ??
	diffuse = v_mul_double(diffuse, light->light_brightness_ratio);
	diffuse = v_mul_double(diffuse, kd);
	diffuse = v_mul(diffuse, closest_obj->colors);
	return (v_mul_double(diffuse, 255.0));
}

/*
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;
	double		light_len;
	t_ray		light_ray;

	light_dir = vminus(light->origin, scene->rec.p);
	light_len = vlength(light_dir);
	light_ray = ray(vplus(scene->rec.p,
				vmult(scene->rec.normal, EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color3(0, 0, 0));
	light_dir = vunit(light_dir);
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
	diffuse = vdivide(light->light_color, 255);
	diffuse = vmult(diffuse, light->bright_ratio);
	diffuse = vmult(diffuse, kd);
	diffuse = vmult_(diffuse, scene->rec.color);
	return (diffuse);
}
*/

/// @brief 광선이 물체에 닿으면 그 물체의 색 반환. ray를 쏴서 hit된 부분을 찾고 hit의 유효성을 판단.
/// hit.d < 0 : 광선이 물체에 부딪히지 않는다.
/// hit.d = 0 : 광선이 물체에 한번 부딪힌다.
/// hit.d > 0 : 광선이 물체에 두번 부딪힌다.
/// @param obj 특정 물체
/// @param ray 한 픽셀에 대한
/// @return
static t_vec3	trace_ray(t_info *info, t_list *objs, t_ray ray)
{
	t_obj	*obj;
	t_hit	hit;
	double	closest;
	t_hit	closest_hit;
	t_obj	*closest_obj;

	closest = 100000;
	closest_hit.d = -1;
	while (objs)
	{
		obj = (t_obj *)(objs->content);
		// if (obj->type == PL)
			// (void)hit;
		// else if (obj->type == SP)
		// {
		hit = check_ray_collision_sphere(ray, obj);
		// }
		// else if (obj->type == CY)
			// (void)hit;
		if (hit.d >= 0 && closest > hit.d)
		{
			closest = hit.d;
			closest_hit.d = hit.d;
			closest_hit.normal = hit.normal;
			closest_hit.point = hit.point;
			closest_obj = obj;
		}
		objs = objs->next;
	}
	if (closest_hit.d >= 0.0)
	{
		// return (v_mul_double(closest_obj->colors, closest_hit.d));
		// TODO 각 변수는 상황에 맞게 변경되어야 함.
		closest_obj->amb = vec3(0.0, 0.0, 1.0); // 기본 조명 색깔? ==> 하나로 통일
		closest_obj->diff = vec3(1.0, 0.0, 0.0); // 빛 퍼짐 정도
		closest_obj->spec = vec3(1.0, 1.0, 1.0); // 반짝거림
		closest_obj->ks = 1.0f; //
		closest_obj->alpha = 1.0f; //

		// return (closest_obj->colors);
		t_vec3 light_color = color3(0, 0, 0);
		t_l *lights = info->lights;
		// lights = scene->light;
		while (lights) // 존재하는 모든 광원들에 대한 정반사, 난반사 값을 연결리스트로 돌아가면서 구해준다.
		{
			// if (lights->type == LIGHT_POINT)
			light_color = v_sum(light_color, point_light_get(&closest_hit, lights, closest_obj));
			lights = lights->next;
		}
		// 정반사, 난반사 값을 더했다면 주변광(기본적으로 들어가는 빛, scene->ambient)을 더해준다.
		// light_color = v_divide(v_sum(light_color, v_mul_double(info->amb.colors, info->amb.amb_light_ratio)), 255.0);
		light_color = v_sum(light_color, v_mul_double(info->amb.colors, info->amb.amb_light_ratio));
		return (clamp_3d(v_mul_double(light_color, info->lights->light_brightness_ratio), 0.0, 255.0));
		// v_mul_double(light_color, info->lights->light_brightness_ratio) = 빛의 세기와 색깔을 곱한 값.

		// t_vec3 light = vec3(0.0, 0.0, -1.0); // 화면 뒷쪽
		// Diffuse
		// const t_vec3 dirToLight = norm_3d_vec(v_minus(light, closest_hit.point));
		// const double diff = max_double(v_dot(closest_hit.normal, dirToLight), 0.0);
		// return (v_mul_double(closest_obj->diff, diff));

		// // Specular
		// const t_vec3 reflectDir = v_minus_double(v_mul_double(closest_hit.normal, 2.0 * v_dot(closest_hit.normal, dirToLight)), dirToLight.x, dirToLight.y, dirToLight.z);
		// // const float specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), closest_obj->alpha);
		// const double specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), 1.0);
		// // return (v_mul_double(v_muldouble(closest_obj->spec, specular), closest_obj->ks));

		// // Diffuse + Specular
		// // return sphere->amb + sphere->diff * diff + sphere->spec * specular * sphere->ks;
		// // return (v_mul_double(v_sum(v_sum(v_mul_double(closest_obj->diff, diff), closest_obj->amb), v_mul_double(v_mul_double(closest_obj->spec, specular), closest_obj->ks)), 255.0));
		// return (v_mul_double(v_sum(closest_obj->colors, v_sum(v_sum(v_mul_double(closest_obj->diff, diff), closest_obj->amb), v_mul_double(v_mul_double(closest_obj->spec, specular), closest_obj->ks))), 255.0));
	}
	// return (vec3(0, 0, 0));	// background : black
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

	// printf("coor:[%f, %f, %f], x, y : [%d, %d]", info->cam.coor.x, info->cam.coor.y, info->cam.coor.z, x, y);
	pixel_pos_world = transform_screen_to_world(info, vec2(x, y));

	// 지금은 정투영. 원근투영으로 해야 원근법이 적용됨
	ray_dir = norm_3d_vec(v_minus(pixel_pos_world, info->cam.coor)); // 카메라에 모니터를 보는 각도가 적용된 광선
	pixel_ray = get_ray(info->cam.coor, ray_dir);	// info of cam
	color = clamp_3d(trace_ray(info, info->objs, pixel_ray), 0.0, 255.0); // 최소의 거리의 오브젝트에서 나온 hit 정보를 가지고 색을 반환.
	return (create_trgb(0, color.x, color.y, color.z));
}
