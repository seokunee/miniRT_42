/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:48:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/24 16:03:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"
#include "ray.h"
#include "hit.h"
#include "raytracer.h"
#include "info.h"

void	copy_hit(t_hit *hit_a, t_hit *hit_b)
{
	hit_a->d = hit_b->d;
	hit_a->normal.x = hit_b->normal.x;
	hit_a->normal.y = hit_b->normal.y;
	hit_a->normal.z = hit_b->normal.z;
	hit_a->point.x = hit_b->point.x;
	hit_a->point.y = hit_b->point.y;
	hit_a->point.z = hit_b->point.z;
}

bool		hit(t_list *obj, t_ray *ray, t_hit_record *rec)
{
	bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = false;
	while (obj->content)
	{
		if (hit_obj(obj->content, ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
			rec->obj = obj->content;
		}
		obj = obj->next;
	}
	return (hit_anything);
}

bool		hit_obj(t_objs *obj, t_ray *ray, t_hit_record *rec)
{
	bool	hit_result;

	hit_result = false;
	if (obj->type == SP)
		hit_result = hit_sphere(obj, ray, rec);
	// else if (obj->type == LIGHT)
	// 	hit_result = (false);
	// else if (obj->type == PL)
	// 	hit_result = hit_pl_rotate_check(obj, ray, rec);
	// else if (obj->type == SQ)
	// 	hit_result = hit_sq_rotate_check(obj, ray, rec);
	// else if (obj->type == CY)
	// 	hit_result = hit_cy_rotate_check(obj, ray, rec);
	// else if (obj->type == TR)
	// 	hit_result = hit_triangle(obj, ray, rec);
	// else if (obj->type == CB)
	// 	hit_result = hit_cb_rotate_check(obj, ray, rec);
	// else if (obj->type == PM)
	// 	hit_result = hit_pm_rotate_check(obj, ray, rec);
	return (hit_result);
}
