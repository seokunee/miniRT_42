/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:52:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/02 13:00:41 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "rt_math.h"
#include "parse.h"
#include "thread.h"

void	rotation_minus_light(t_info *rotate)
{
	t_l				*rota_light;

	rota_light = rotate->lights;
	while (rota_light)
	{
		copy_vector_value(&(rota_light->coor), \
		vec3(rota_light->coor.x, rota_light->coor.y, -(rota_light->coor.z)));
		rota_light = rota_light->next;
	}
}

void	rotation_minus_objs(t_info *rotate)
{
	t_list			*rotate_list;
	t_obj			*rotate_obj;

	rotate_list = rotate->objs;
	while (rotate_list)
	{
		rotate_obj = (t_obj *)(rotate_list->content);
		copy_vector_value(&(rotate_obj->coor), \
		vec3(rotate_obj->coor.x, rotate_obj->coor.y, -(rotate_obj->coor.z)));
		copy_vector_value(&(rotate_obj->normal), vec3(rotate_obj->normal.x, \
		rotate_obj->normal.y, -(rotate_obj->normal.z)));
		rotate_list = rotate_list->next;
	}
}

void	rotation_light(t_info *rotate, t_c cam)
{
	const t_vec3	dir_z = vec3(cam.normal.x, cam.normal.y, cam.normal.z);
	const t_vec3	dir_x = v_cross(dir_z, vec3(0, 0, 1));
	const t_vec3	dir_y = v_cross(dir_x, dir_z);
	t_l				*rotate_light;

	rotate_light = rotate->lights;
	while (rotate_light)
	{
		copy_vector_value(&(rotate_light->coor), vec3( \
			v_element_sum(v_mul(dir_x, rotate_light->coor)),\
			v_element_sum(v_mul(dir_y, rotate_light->coor)),\
			v_element_sum(v_mul(dir_z, rotate_light->coor))));
		rotate_light = rotate_light->next;
	}
}

void	rotation_objs(t_info *rotate, t_c cam)
{
	const t_vec3	dir_z = vec3(cam.normal.x, cam.normal.y, cam.normal.z);
	const t_vec3	dir_x = v_cross(dir_z, vec3(0, 0, 1));
	const t_vec3	dir_y = v_cross(dir_x, dir_z);

	t_list			*rotate_list;
	t_obj			*rotate_obj;

	rotate_list = rotate->objs;
	while (rotate_list)
	{
		rotate_obj = (t_obj *)(rotate_list->content);
		copy_vector_value(&(rotate_obj->coor), vec3(\
			v_element_sum(v_mul(dir_x, rotate_obj->coor)), \
			v_element_sum(v_mul(dir_y, rotate_obj->coor)), \
			v_element_sum(v_mul(dir_z, rotate_obj->coor))));
		copy_vector_value(&(rotate_obj->normal), vec3(\
			v_element_sum(v_mul(dir_x, rotate_obj->normal)), \
			v_element_sum(v_mul(dir_y, rotate_obj->normal)), \
			v_element_sum(v_mul(dir_z, rotate_obj->normal))));
		rotate_list = rotate_list->next;
	}
}

void	rotation_minus(t_info *rotate)
{
	rotation_minus_light(rotate);
	rotation_minus_objs(rotate);
}

void	rotation(t_info *rotate, t_info *info)
{
	rotation_light(rotate, info->cam);
	rotation_objs(rotate, info->cam);
}

void	rotate(t_info *rotate, t_info *info)
{
	init_parallel_movement(rotate, info);
	if (info->cam.normal.z == -1)
		rotation_minus(rotate);
	else if (info->cam.normal.z != 1)
		rotation(rotate, info);
	start_drawing(rotate);
}
