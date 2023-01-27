/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:17 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/27 17:38:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"

/*
int	hit_cylinder_cap(t_object *cy_obj, t_ray *ray,
	t_hit_record *rec, double height)
{
	t_cylinder	*cy;
	t_vec3		circle_center;
	double		r;
	float		root;

	cy = cy_obj->element;
	r = cy->diameter / 2;
	circle_center = vplus(cy->center, vmult(cy->dir, height));
	root = vdot(vminus(circle_center, ray->origin), cy->dir) \
		/ vdot(ray->dir, cy->dir);
	if (fabs(r) < fabs(vlength(vminus(circle_center, ray_at(ray, root)))))
		return (0);
	if (root < rec->tmin || rec->tmax < root)
		return (0);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = rec->t;
	if (0 < height)
		rec->normal = cy->dir;
	else
		rec->normal = vmult(cy->dir, -1);
	set_face_normal(ray, rec);
	rec->color = cy_obj->color;
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
