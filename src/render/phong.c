/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:01:17 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 16:18:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "structs.h"
#include "rt_math.h"
#include "window.h"

bool	in_shadow(t_list *objs, t_ray light_ray)
{
	t_hit			closest_hit;
	t_obj			*closest_obj;

	get_closest_hit_obj(objs, &closest_hit, light_ray, &closest_obj);
	if (closest_hit.d >= 0.0)
		return (true);
	return (false);
}

t_color3	get_specular(t_info *info, t_hit *hit, t_l *light, t_vec3 light_dir)
{
	double		spec;
	t_color3	specular;

	const t_vec3	reflect = v_minus(v_mul_double(v_mul_double(hit->normal, v_dot(hit->normal, light_dir)), 2), light_dir);
	const t_vec3	view_dir = vunit(v_mul_double(info->ray.normal, -1));
	spec = pow(fmax(v_dot(view_dir, reflect), 0.0), 2);
	specular = v_mul_double(v_mul_double(light->colors, 1.0f), spec);
	return (specular);
}

t_color3	point_light_get(\
	// t_list *objs, t_hit *hit, t_l *light, t_obj *closest_obj, t_ray ray)
	t_info *info, t_hit *hit, t_l *light, t_obj *closest_obj)
{
	const t_vec3	light_dir = vunit(v_minus(light->coor, hit->point));
	t_color3		diffuse;
	t_ray			light_ray;
	double			kd;

	light_ray = get_ray(\
		v_sum(hit->point, v_mul_double(hit->normal, 0.001)), light_dir);
	if (in_shadow(info->objs, light_ray))
		return (black_v3());
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(v_dot(hit->normal, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값. --> 0.몇값이 나옴.
	// fmax 함수는 두 개의 인자 중 큰 값을 리턴한다. 만약 코사인세타가 둔각이 될 경우 음수가 되기에 0을 리턴하도록 한다.
	diffuse = v_divide(light->colors, 255.0);
	diffuse = v_mul_double(diffuse, light->light_brightness_ratio);
	diffuse = v_mul_double(diffuse, kd);
	diffuse = v_mul(diffuse, closest_obj->colors);

	diffuse = v_sum(diffuse, get_specular(info, hit, light, light_dir));
	// const t_vec3 reflect = v_minus(v_mul_double(v_mul_double(hit->normal, v_dot(hit->normal, light_dir)), 2), light_dir);
	// t_vec3 view_dir = vunit(v_mul_double(info->ray.normal, -1));
	// double ksn = 64; // shininess value 임의로 설정해줄값. 값을 제곱하기때문에 값이 클수록 빛이 더 한점으로 모이게된다.
	// double ks = 0.5; // specular strength 각 물체가 가지는 반사의 정도.
	// double spec = pow(fmax(v_dot(view_dir, reflect), 0.0), 2);
	// t_color3 specular = v_mul_double(v_mul_double(light->colors, 1.0f), spec);
	// return (v_sum(diffuse, specular));
	return (diffuse);
}
