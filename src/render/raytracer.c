/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/26 20:10:06 by chanwjeo         ###   ########.fr       */
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
	return (vec3(x_scale, y_scale, info->t_c.length));
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
static t_vec3	trace_ray(t_list *objs, t_ray ray)
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
		closest_obj->amb = vec3(0.0, 0.0, 1.0); // 기본 조명 색깔?
		closest_obj->diff = vec3(1.0, 0.0, 0.0); // 빛 퍼짐 정도
		closest_obj->spec = vec3(1.0, 1.0, 1.0); // 반짝거림
		closest_obj->ks = 1.0f; //
		closest_obj->alpha = 1.0f; //

		t_vec3 light = vec3(0.0, 0.0, -1.0); // 화면 뒷쪽
		// Diffuse
		const t_vec3 dirToLight = norm_3d_vec(v_minus(light, closest_hit.point));
		const double diff = max_double(v_dot(closest_hit.normal, dirToLight), 0.0);
		// return (v_mul_double(closest_obj->diff, diff));

		// Specular
		const t_vec3 reflectDir = v_minus_double(v_mul_double(closest_hit.normal, 2.0 * v_dot(closest_hit.normal, dirToLight)), dirToLight.x, dirToLight.y, dirToLight.z);
		// const float specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), closest_obj->alpha);
		const double specular = pow(max_double(v_dot(vec3(-ray.normal.x, -ray.normal.y, -ray.normal.z), reflectDir), 0.0), 1.0);
		// return (v_mul_double(v_muldouble(closest_obj->spec, specular), closest_obj->ks));

		// Diffuse + Specular
		// return sphere->amb + sphere->diff * diff + sphere->spec * specular * sphere->ks;
		// return (v_mul_double(v_sum(v_sum(v_mul_double(closest_obj->diff, diff), closest_obj->amb), v_mul_double(v_mul_double(closest_obj->spec, specular), closest_obj->ks)), 255.0));
		return (v_mul_double(v_sum(closest_obj->colors, v_sum(v_sum(v_mul_double(closest_obj->diff, diff), closest_obj->amb), v_mul_double(v_mul_double(closest_obj->spec, specular), closest_obj->ks))), 255.0));
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

	// printf("coor:[%f, %f, %f], x, y : [%d, %d]", info->t_c.coor.x, info->t_c.coor.y, info->t_c.coor.z, x, y);
	pixel_pos_world = transform_screen_to_world(info, vec2(x, y));

	// 지금은 정투영. 원근투영으로 해야 원근법이 적용됨
	ray_dir = norm_3d_vec(v_minus(pixel_pos_world, info->t_c.coor)); // 카메라에 모니터를 보는 각도가 적용된 광선
	pixel_ray = get_ray(info->t_c.coor, ray_dir);	// info of cam
	color = clamp_3d(trace_ray(info->objs, pixel_ray), 0.0, 255.0); // 최소의 거리의 오브젝트에서 나온 hit 정보를 가지고 색을 반환.
	return (create_trgb(0, color.x, color.y, color.z));
}
