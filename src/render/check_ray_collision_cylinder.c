/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_collision_cylinder.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:16:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/03 13:58:20 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"

void	hit_cylinder_cap(t_ray ray, t_obj *cy, t_hit *hit, double hei)
{
	t_vec3	circle_center;
	double	r;
	double	root;

	r = cy->diameter / 2;
	circle_center = v_sum(cy->coor, v_mul_double(cy->normal, hei)); // 실린더 좌표에서 nor 방향으로 hei만큼 이동하면 실린더의 끝 원 중심이 된다.
	root = v_dot(v_minus(circle_center, ray.orig), cy->normal) / \
		v_dot(ray.normal, cy->normal); // ray에서 cap까지의 거리
	if (fabs(r) < fabs(v_len(v_minus(circle_center, ray_at(ray, root))))) // 반지름 안에 있는지 확인
		return ;
	if (root < 0.001 || root > 1000) // 빛이 영향은 무한대가 아니므로 영향 거리를 정해줌.
		return ;
	if (hit->d != -1.0 && hit->d <= root)
		return ;
	hit->d = root;
	hit->point = ray_at(ray, root);
	if (0 < hei)
		hit->normal = cy->normal; // 위 cap 인경우
	else
		hit->normal = v_mul_double(cy->normal, -1); // 아래 cap인 경우
	if (v_dot(ray.normal, hit->normal) >= 0)
		hit->normal = v_mul_double(hit->normal, -1); // 아래
}

static bool	cy_boundary(t_obj *cy, t_vec3 at_point, t_cy_settings *set)
{
	double	max_height;

	set->hit_height = v_dot(v_minus(at_point, cy->coor), cy->normal);
	max_height = cy->cy_hei / 2;
	if (fabs(set->hit_height) > max_height) // 원기둥 높이 안에 있는 확인
		return (false);
	return (true);
}

static bool	valid_cy_hit(t_cy_settings *set, t_obj *cy, t_ray ray)
{
	set->u = ray.normal;
	set->o = cy->normal;
	set->r = cy->diameter / 2;
	set->delta_p = v_minus(ray.orig, cy->coor); // 원기둥 중심에서 ray 시작점으로 향하는 벡터
	set->a = pow(v_len(v_cross(set->u, set->o)), 2); //
	set->half_b = v_dot(v_cross(set->u, set->o), v_cross(set->delta_p, set->o));
	set->c = pow(v_len(v_cross(set->delta_p, set->o)), 2) - pow(set->r, 2);
	set->discriminant = set->half_b * set->half_b - set->a * set->c;
	if (set->discriminant < 0)
		return (false);
	set->sqrtd = sqrt(set->discriminant);
	set->root = (-set->half_b - set->sqrtd) / set->a;
	if (set->root < 0.001 || set->root > 10000) // 고민해야할 부분 우리 원기둥은 거리 측정하는데 sphere은 측정하지 않음 모순쓰.
	{
		set->root = (-set->half_b + set->sqrtd) / set->a; // 이거 왜 한번 더 한거지?
		if (set->root < 0.001 || set->root > 10000)
			return (false);
	}
	return (cy_boundary(cy, ray_at(ray, set->root), set));
}

static void	hit_cylinder_side(t_ray ray, t_obj *cy, t_hit *hit)
{
	t_cy_settings	cy_set;

	if (valid_cy_hit(&cy_set, cy, ray) == false)
		return ;
	if (hit->d != -1.0 && hit->d <= cy_set.root)
		return ;
	hit->d = cy_set.root;
	hit->point = ray_at(ray, cy_set.root);
	hit->normal = vunit(v_minus(hit->point, v_sum(cy->coor, v_mul_double(cy->normal, cy_set.hit_height))));
	if (v_dot(ray.normal, hit->normal) >= 0)
		hit->normal = v_mul_double(hit->normal, -1);
}

t_hit	check_ray_collision_cylinder(t_ray ray, t_obj *cylinder)
{
	t_hit	hit;

	hit = get_hit(-1.0, vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0));
	hit_cylinder_cap(ray, cylinder, &hit, cylinder->cy_hei / 2);
	hit_cylinder_cap(ray, cylinder, &hit, -(cylinder->cy_hei / 2));
	hit_cylinder_side(ray, cylinder, &hit);
	return (hit);
}
