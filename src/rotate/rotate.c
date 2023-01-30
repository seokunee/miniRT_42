/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:52:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/30 19:23:31 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "rt_math.h"
#include "parse.h"

/*
void	set_rotate_info(t_info *rotate, t_info *info)
{
	// 회전하기위한 변환벡터 구하기
	t_vec3	dir_z = vec3(info->cam.normal.x, info->cam.normal.y, info->cam.normal.z);
	// t_vec3	dir_y = v_cross(vec3(0, 0, 1), dir_z);
	// t_vec3	dir_x = v_cross(dir_z, dir_y);
	t_vec3	dir_y = v_cross(dir_z, vec3(0, 0, 1));
	t_vec3	dir_x = v_cross(dir_y, dir_z);
	printf("dir_x : [%f, %f, %f]\n", dir_x.x, dir_x.y, dir_x.z);
	printf("dir_y : [%f, %f, %f]\n", dir_y.x, dir_y.y, dir_y.z);
	printf("dir_z : [%f, %f, %f]\n", dir_z.x, dir_z.y, dir_z.z);

	// light 회전
	t_l	*rotate_light = rotate->lights;
	while (rotate_light)
	{
		t_vec3	tmp_vec3 = vec3(v_element_sum(v_mul(dir_x, rotate_light->coor)), v_element_sum(v_mul(dir_y, rotate_light->coor)), v_element_sum(v_mul(dir_z, rotate_light->coor)));
		copy_vector_value(&(rotate_light->coor), tmp_vec3);
		// rotate_light->coor.x = tmp_vec3.x;
		// rotate_light->coor.y = tmp_vec3.y;
		// rotate_light->coor.z = tmp_vec3.z;
		rotate_light = rotate_light->next;
	}

	// objs 회전
	t_list	*rotate_list = rotate->objs;
	while (rotate_list)
	{
		t_obj *rotate_obj = (t_obj *)(rotate_list->content);
		printf("rotate_obj.normal : [%f, %f, %f]\n", rotate_obj->normal.x, rotate_obj->normal.y, rotate_obj->normal.z);
		t_vec3	tmp_vec3_coor =	vec3(v_element_sum(v_mul(dir_x, rotate_obj->coor)),
			v_element_sum(v_mul(dir_y, rotate_obj->coor)),
			v_element_sum(v_mul(dir_z, rotate_obj->coor)));
		t_vec3	tmp_vec3_normal = vec3(v_element_sum(v_mul(dir_x, rotate_obj->normal)),
			v_element_sum(v_mul(dir_y, rotate_obj->normal)),
			v_element_sum(v_mul(dir_z, rotate_obj->normal)));
		printf("tmp_vec3_normal : [%f, %f, %f]\n", tmp_vec3_normal.x, tmp_vec3_normal.y, tmp_vec3_normal.z);
		copy_vector_value(&(rotate_obj->coor), tmp_vec3_coor);
		copy_vector_value(&(rotate_obj->normal), tmp_vec3_normal);
		rotate_list = rotate_list->next;
	}
}
*/

void	init_rotate_1(t_info *rotate, t_info *info)
{
	// ft_memcpy(&rotate->win, &info->win, sizeof(&rotate->win));
	rotate->win.height = info->win.height;
	rotate->win.width = info->win.width;
	rotate->win.mlx = info->win.mlx;
	rotate->win.mlx_win = info->win.mlx_win;
	rotate->amb.amb_light_ratio = info->amb.amb_light_ratio;
	copy_vector_value(&(rotate->amb.colors), info->amb.colors);
	rotate->cam.coor.x = 0.0;
	rotate->cam.coor.y = 0.0;
	rotate->cam.coor.z = 0.0;
	rotate->cam.normal.x = 0.0;
	rotate->cam.normal.y = 0.0;
	rotate->cam.normal.z = 1.0;
	rotate->cam.fov = info->cam.fov;
	rotate->cam.length = info->cam.length;
}

void	init_rotate_light(t_info *rotate, t_info *info)
{
	t_l	*info_light;
	t_l *tmp_light;

	rotate->lights = 0;
	info_light = info->lights;
	while (info_light)
	{
		tmp_light = ft_malloc(sizeof(t_l));
		copy_vector_value(&(tmp_light->coor), v_minus(info_light->coor, info->cam.coor));
		copy_vector_value(&(tmp_light->colors), info_light->colors);
		tmp_light->light_brightness_ratio = info_light->light_brightness_ratio;
		ft_light_add(rotate, tmp_light);
		info_light = info_light->next;
	}
}

void	init_rotate_objs(t_info *rotate, t_info *info)
{
	t_list	*objs;
	t_list	*tmp_objs;
	t_obj	*obj;
	t_obj	*tmp_obj;

	objs = info->objs;
	rotate->objs = NULL;
	while (objs)
	{
		obj = objs->content;
		tmp_objs = ft_malloc(sizeof(t_list));
		tmp_objs->content = ft_malloc(sizeof(t_obj));
		tmp_objs->next = NULL;
		tmp_obj = tmp_objs->content;
		tmp_obj->type = obj->type;
		copy_vector_value(&(tmp_obj->coor), v_minus(obj->coor, info->cam.coor));
		copy_vector_value(&(tmp_obj->normal), obj->normal);
		copy_vector_value(&(tmp_obj->colors), obj->colors);
		tmp_obj->diameter = obj->diameter;
		tmp_obj->cy_hei = obj->cy_hei;
		ft_lstadd_back(&(rotate->objs), tmp_objs);
		objs = objs->next;
	}
}

// info에서 rotate로 먼저 옮길만한 것들 옮겨주기 (값 복사)
void	init_parallel_movement(t_info *rotate, t_info *info)
{
	init_rotate_1(rotate, info);
	init_rotate_light(rotate, info);
	init_rotate_objs(rotate, info);
}

void	rotation_minus_light(t_info *rotate)
{
	t_l				*rotate_light;

	rotate_light = rotate->lights;
	while (rotate_light)
	{
		copy_vector_value(&(rotate_light->coor), vec3(rotate_light->coor.x, rotate_light->coor.y, -(rotate_light->coor.z)));
		rotate_light = rotate_light->next;
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
		copy_vector_value(&(rotate_obj->coor), vec3(rotate_obj->coor.x, rotate_obj->coor.y, -(rotate_obj->coor.z)));
		copy_vector_value(&(rotate_obj->normal), vec3(rotate_obj->normal.x, rotate_obj->normal.y, -(rotate_obj->normal.z)));
		rotate_list = rotate_list->next;
	}
}

void	rotation_light(t_info *rotate, t_c cam)
{
	const t_vec3	dir_z = vec3(cam.normal.x, cam.normal.y, cam.normal.z);
	const t_vec3	dir_y = v_cross(dir_z, vec3(0, 0, 1));
	const t_vec3	dir_x = v_cross(dir_y, dir_z);
	t_l				*rotate_light;

	rotate_light = rotate->lights;
	while (rotate_light)
	{
		copy_vector_value(&(rotate_light->coor), vec3(v_element_sum(v_mul(dir_x, rotate_light->coor)),\
		v_element_sum(v_mul(dir_y, rotate_light->coor)), v_element_sum(v_mul(dir_z, rotate_light->coor))));
		rotate_light = rotate_light->next;
	}
}

void	rotation_objs(t_info *rotate, t_c cam)
{
	const t_vec3	dir_z = vec3(cam.normal.x, cam.normal.y, cam.normal.z);
	const t_vec3	dir_y = v_cross(dir_z, vec3(0, 0, 1));
	const t_vec3	dir_x = v_cross(dir_y, dir_z);
	t_list			*rotate_list;
	t_obj			*rotate_obj;

	rotate_list = rotate->objs;
	while (rotate_list)
	{
		rotate_obj = (t_obj *)(rotate_list->content);
		copy_vector_value(&(rotate_obj->coor), vec3(\
			v_element_sum(v_mul(dir_x, rotate_obj->coor)),
			v_element_sum(v_mul(dir_y, rotate_obj->coor)),
			v_element_sum(v_mul(dir_z, rotate_obj->coor))));
		copy_vector_value(&(rotate_obj->normal), vec3(\
			v_element_sum(v_mul(dir_x, rotate_obj->normal)),
			v_element_sum(v_mul(dir_y, rotate_obj->normal)),
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
	// info에서 rotate로 먼저 옮길만한 것들 옮겨주기 (값 복사)
	// + 평행이동 Parallel movement
	init_parallel_movement(rotate, info);
	// 회전 시켜야하는지 확인
	// z가 1인지 확인하면 normalize 된 벡터이기 때문에 자동으로 (0, 0, 1) 벡터이다.
	if (info->cam.normal.z == -1)
		rotation_minus(rotate);
	else if (info->cam.normal.z != 1)
		rotation(rotate, info);
}