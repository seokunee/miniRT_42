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

void	init_rotate_from_info_other(t_info *rotate, t_info *info)
{
	copy_vector_value(&(rotate->amb.colors), info->amb.colors);
	rotate->amb.amb_light_ratio = info->amb.amb_light_ratio;
	rotate->cam.coor.x = 0.0;
	rotate->cam.coor.y = 0.0;
	rotate->cam.coor.z = 0.0;
	rotate->cam.normal.x = 0.0;
	rotate->cam.normal.y = 0.0;
	rotate->cam.normal.z = 1.0;
	rotate->cam.fov = info->cam.fov;
	rotate->cam.length = info->cam.length;
	rotate->num_ele.a_count = info->num_ele.a_count;
	rotate->num_ele.c_count = info->num_ele.c_count;
	rotate->num_ele.l_count = info->num_ele.l_count;
	rotate->num_ele.objs_count = info->num_ele.objs_count;
}

void	init_rotate_from_info_win(t_info *rotate, t_info *info)
{
	rotate->win.height = info->win.height;
	rotate->win.width = info->win.width;
	rotate->win.mlx = info->win.mlx;
	rotate->win.mlx_win = info->win.mlx_win;
	rotate->win.terminal.cam_on = info->win.terminal.cam_on;
	rotate->win.terminal.light_on = info->win.terminal.light_on;
	rotate->win.terminal.light_select = info->win.terminal.light_select;
	rotate->win.terminal.curr_light = info->win.terminal.curr_light;
	rotate->win.terminal.prompt = info->win.terminal.prompt;
	rotate->win.terminal.obj_on = info->win.terminal.obj_on;
	rotate->win.terminal.obj_select = info->win.terminal.obj_select;
	rotate->win.terminal.curr_obj = info->win.terminal.curr_obj;
	init_rotate_from_info_other(rotate, info);
}

void	init_rotate_light(t_info *rotate, t_info *info)
{
	t_l	*info_light;
	t_l	*tmp_light;

	rotate->lights = 0;
	info_light = info->lights;
	while (info_light)
	{
		tmp_light = ft_malloc(sizeof(t_l));
		copy_vector_value(&(tmp_light->coor), \
		v_minus(info_light->coor, info->cam.coor));
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
		tmp_obj->texture.type = obj->texture.type;
		tmp_obj->texture.width = obj->texture.width;
		tmp_obj->texture.height = obj->texture.height;
		tmp_obj->texture.data.addr = obj->texture.data.addr;
		tmp_obj->texture.data.bits_per_pixel = obj->texture.data.bits_per_pixel;
		tmp_obj->texture.data.endian = obj->texture.data.endian;
		tmp_obj->texture.data.img = obj->texture.data.img;
		tmp_obj->texture.data.line_length = obj->texture.data.line_length;
		if (obj->texture_nomal.type != NONE)
		{
			tmp_obj->texture_nomal.type = obj->texture_nomal.type;
			tmp_obj->texture_nomal.width = obj->texture_nomal.width;
			tmp_obj->texture_nomal.height = obj->texture_nomal.height;
			tmp_obj->texture_nomal.data.addr = obj->texture_nomal.data.addr;
			tmp_obj->texture_nomal.data.bits_per_pixel = obj->texture_nomal.data.bits_per_pixel;
			tmp_obj->texture_nomal.data.endian = obj->texture_nomal.data.endian;
			tmp_obj->texture_nomal.data.img = obj->texture_nomal.data.img;
			tmp_obj->texture_nomal.data.line_length = obj->texture_nomal.data.line_length;
		}
		ft_lstadd_back(&(rotate->objs), tmp_objs);
		objs = objs->next;
	}
}

// info에서 rotate로 먼저 옮길만한 것들 옮겨주기 (값 복사)
void	init_parallel_movement(t_info *rotate, t_info *info)
{
	init_rotate_from_info_win(rotate, info);
	init_rotate_light(rotate, info);
	init_rotate_objs(rotate, info);
}
