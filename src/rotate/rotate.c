/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:52:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/28 19:20:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "rt_math.h"

/*
void	set_rotate_info(t_info *rotate, t_info *info)
{
	//window
	rotate->win.height = info->win.height;
	rotate->win.width = info->win.width;
	rotate->win.mlx = info->win.mlx;
	rotate->win.mlx_win = info->win.mlx_win;

	//ambient
	rotate->amb.amb_light_ratio = info->amb.amb_light_ratio;
	copy_vector_value(&(rotate->amb.colors), info->amb.colors);

	//camera
	rotate->cam.coor.x = 0.0;
	rotate->cam.coor.y = 0.0;
	rotate->cam.coor.z = 0.0;
	rotate->cam.normal.x = 0.0;
	rotate->cam.normal.y = 0.0;
	rotate->cam.normal.z = 1.0;
	rotate->cam.fov = info->cam.fov;
	rotate->cam.length = info->cam.length;

	//light 평행이동
	rotate->lights = 0;
	t_l	*info_light = info->lights;
	t_l *tmp_light;
	while (info_light)
	{
		tmp_light = ft_calloc(sizeof(t_l), 1);
		if (!tmp_light)
			error_exit("malloc error");
		tmp_light->coor.x = info_light->coor.x - info->cam.coor.x;
		tmp_light->coor.y = info_light->coor.y - info->cam.coor.y;
		tmp_light->coor.z = info_light->coor.z - info->cam.coor.z;
		copy_vector_value(&(tmp_light->colors), info_light->colors);
		tmp_light->light_brightness_ratio = info_light->light_brightness_ratio;
		// tmp_light->colors.x = info_light->colors.x;
		// tmp_light->colors.y = info_light->colors.y;
		// tmp_light->colors.z = info_light->colors.z;
		ft_light_add(rotate, tmp_light);
		info_light = info_light->next;
	}

	//object 평행이동
	rotate->objs = 0;
	t_list	*info_objs = info->objs;
	t_list	*tmp_list;
	while (info_objs)
	{
		tmp_list = malloc(sizeof(t_list));
		if (!tmp_list)
			error_exit("malloc error");
		tmp_list->next = 0;
		tmp_list->content = ft_calloc(sizeof(t_obj), 1);
		((t_obj *)(tmp_list->content))->type = ((t_obj *)(info_objs->content))->type;
		((t_obj *)(tmp_list->content))->coor.x = ((t_obj *)(info_objs->content))->coor.x - info->cam.coor.x;
		((t_obj *)(tmp_list->content))->coor.y = ((t_obj *)(info_objs->content))->coor.y - info->cam.coor.y;
		((t_obj *)(tmp_list->content))->coor.z = ((t_obj *)(info_objs->content))->coor.z - info->cam.coor.z;
		copy_vector_value(&(((t_obj *)(tmp_list->content))->normal), ((t_obj *)(info_objs->content))->normal);
		copy_vector_value(&(((t_obj *)(tmp_list->content))->colors), ((t_obj *)(info_objs->content))->colors);
		((t_obj *)(tmp_list->content))->diameter = ((t_obj *)(info_objs->content))->diameter;
		((t_obj *)(tmp_list->content))->cy_hei = ((t_obj *)(info_objs->content))->cy_hei;
		ft_lstadd_back(&(rotate->objs), tmp_list);
		info_objs = info_objs->next;
	}

	// 회전
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

// info에서 rotate로 먼저 옮길만한 것들 옮겨주기 (값 복사)
void	init_rotate(t_info *rotate, t_info *info)
{
	init_rotate_1(rotate, info);
	// while light;

	// while objs;

}

void	light_parallel_movement(t_info *rotate, t_info *info)
{
	rotate->lights = 0;
	t_l	*info_light = info->lights;
	t_l *tmp_light;
	while (info_light)
	{
		tmp_light = ft_calloc(sizeof(t_l), 1);
		if (!tmp_light)
			error_exit("malloc error");
		tmp_light->coor.x = info_light->coor.x - info->cam.coor.x;
		tmp_light->coor.y = info_light->coor.y - info->cam.coor.y;
		tmp_light->coor.z = info_light->coor.z - info->cam.coor.z;
		copy_vector_value(&(tmp_light->colors), info_light->colors);
		tmp_light->light_brightness_ratio = info_light->light_brightness_ratio;
		// tmp_light->colors.x = info_light->colors.x;
		// tmp_light->colors.y = info_light->colors.y;
		// tmp_light->colors.z = info_light->colors.z;
		ft_light_add(rotate, tmp_light);
		info_light = info_light->next;
	}
}

void	rotate(t_info *rotate, t_info *info)
{
	// info에서 rotate로 먼저 옮길만한 것들 옮겨주기 (값 복사)
	init_rotate(rotate, info);
	// 평행이동 해야하는지 확인
	// light 평행이동
	light_parallel_movement(rotate, info);
	// 평행이동 부분

	// 회전 시켜야하는지 확인

	// 회전 부분
}
