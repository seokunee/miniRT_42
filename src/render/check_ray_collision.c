/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:17 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/27 20:52:04 by chanwjeo         ###   ########.fr       */
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
		v_dot(ray.normal, cy->normal); // 광선에서 뚜껑 원 중심점으로 가는 벡터와 cy.nor를 dot하면 ray의
	if (fabs(r) < fabs(v_len(v_minus(circle_center, ray_at(ray, root)))))
		return ;
	if (root < 0.001 || root > 1000) // 0.001 = tmin , 1000 = tmax??
		return ;
	hit->point = ray_at(ray, root);
	hit->d = root;
	if (0 < hei)
		hit->normal = cy->normal;
	else
		hit->normal = v_mul_double(cy->normal, -1);
	if (v_dot(ray.normal, hit->normal) >= 0)
		hit->normal = v_mul_double(hit->normal, -1);
}

/*
int	cy_boundary(t_cylinder *cy, t_vec3 at_point, t_cylinops *c)
{
	double	hit_height;
	double	max_height;

	hit_height = vdot(vminus(at_point, cy->center), cy->dir);
	max_height = cy->height / 2;
	c->hit_height = hit_height;
	if (fabs(c->hit_height) > max_height)
		return (0);
	return (1);
}

int	hit_cylinder_value_setter(t_cylinops *c,
	t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	c->cy = cy_obj->element;
	c->u = ray->dir;
	c->o = c->cy->dir;
	c->r = c->cy->diameter / 2;
	c->delta_p = vminus(ray->origin, c->cy->center);
	c->a = vlength2(vcross(c->u, c->o));
	c->half_b = vdot(vcross(c->u, c->o), vcross(c->delta_p, c->o));
	c->c = vlength2(vcross(c->delta_p, c->o)) - pow(c->r, 2);
	c->discriminant = c->half_b * c->half_b - c->a * c->c;
	if (c->discriminant < 0)
		return (0);
	c->sqrtd = sqrt(c->discriminant);
	c->root = (-c->half_b - c->sqrtd) / c->a;
	if (c->root < rec->tmin || rec->tmax < c->root)
	{
		c->root = (-c->half_b + c->sqrtd) / c->a;
		if (c->root < rec->tmin || rec->tmax < c->root)
			return (0);
	}
	return (cy_boundary(c->cy, ray_at(ray, c->root), c));
}

int	hit_cylinder_side(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinops	cylinder_ops;

	cylinder_ops.cy = 0;
	if (!hit_cylinder_value_setter(&cylinder_ops, cy_obj, ray, rec))
		return (0);
	rec->t = cylinder_ops.root;
	rec->p = ray_at(ray, cylinder_ops.root);
	rec->normal = get_cylinder_normal(cylinder_ops.cy,
			rec->p, cylinder_ops.hit_height);
	set_face_normal(ray, rec);
	rec->color = cy_obj->color;
	return (1);
}

*/

static bool	cy_boundary(t_obj *cy, t_vec3 at_point, t_cy_settings *set)
{
	double	max_height;

	set->hit_height = v_dot(v_minus(at_point, cy->coor), cy->normal);
	max_height = cy->cy_hei / 2;
	if (fabs(set->hit_height) > max_height)
		return (false);
	return (true);
}

static bool	valid_cy_hit(t_cy_settings *set, t_obj *cy, t_ray ray)
{
	set->u = ray.normal;
	set->o = cy->normal;
	set->r = cy->diameter / 2;
	set->delta_p = v_minus(ray.orig, cy->coor);
	set->a = v_len(v_cross(set->u, set->o));
	set->half_b = v_dot(v_cross(set->u, set->o), v_cross(set->delta_p, set->o));
	set->c = v_len(v_cross(set->delta_p, set->o)) - pow(set->r, 2);
	set->discriminant = set->half_b * set->half_b - set->a * set->c;
	if (set->discriminant < 0)
		return (false);
	set->sqrtd = sqrt(set->discriminant);
	set->root = (-set->half_b - set->sqrtd) / set->a;
	if (set->root < 0.001 || set->root > 10000)
	{
		set->root = (-set->half_b + set->sqrtd) / set->a;
		if (set->root < 0.001 || set->root > 10000)
			return (false);
	}
	return (cy_boundary(cy, ray_at(ray, set->root), set));
}

void	hit_cylinder_side(t_ray ray, t_obj *cy, t_hit *hit)
{
	t_cy_settings	cy_set;

	if (valid_cy_hit(&cy_set, cy, ray) == false)
		return ;
	hit->d = cy_set.root;
	printf("side hit->d : %f\n", hit->d);
	hit->point = ray_at(ray, cy_set.root);
	hit->normal = vunit(v_minus(hit->point, v_sum(cy->coor, v_mul_double(cy->normal, cy_set.hit_height))));
	if (v_dot(ray.normal, hit->normal) >= 0)
		hit->normal = v_mul_double(hit->normal, -1);
}

// t_vec3	get_cylinder_normal(t_cylinder *cy, t_vec3 at_point, double hit_height)
// {
// 	t_point3	hit_center;
// 	t_vec3		normal;

// 	hit_center = vplus(cy->center, vmult(cy->dir, hit_height));
// 	normal = vminus(at_point, hit_center);
// 	return (vunit(normal));
// }


/*
t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	const t_cylinder	*cy;
	int					result;

	cy = cy_obj->element;
	result = 0;
	result += hit_cylinder_cap(cy_obj, ray, rec, cy->height / 2);
	result += hit_cylinder_cap(cy_obj, ray, rec, -(cy->height / 2));
	result += hit_cylinder_side(cy_obj, ray, rec);
	return (result);
}*/

t_hit	check_ray_collision_cylinder(t_ray ray, t_obj *cylinder)
{
	t_hit	hit;

	hit = get_hit(-1.0, vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0)); // hit 초기화
	hit_cylinder_cap(ray, cylinder, &hit, cylinder->cy_hei / 2);
	hit_cylinder_cap(ray, cylinder, &hit, -(cylinder->cy_hei / 2));
	hit_cylinder_side(ray, cylinder, &hit);
	// printf("hit.d : %f\n", hit.d);
	return (hit);
}

/// @brief ray가 sphere의 어디에서 부딪히는지 계산한 hit 구조체를 반환한다.
/// @param ray
/// @param sphere 구체에 대한 정보를 가진 구조체
/// @return
t_hit	check_ray_collision_sphere(t_ray ray, t_obj *sphere)
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
