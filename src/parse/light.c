/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko <ko@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 19:10:01 by ko               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_light(t_info *info, char **s)
{
	t_l	*light;
	//ft_lstadd_back
	light = ft_calloc(sizeof(t_l), 1);
	if (!light)
		error_exit("malloc error");
	if (sec_arr_len(s) != 3 && sec_arr_len(s) != 4)
		error_exit("Wrong argument");
	info->t_l->coor = get_arg_coor(s[1]);
	info->t_l->light_brightness_ratio = ft_atof(s[2]);
	if (check_range(1, info->t_l->light_brightness_ratio) == ERR)
		error_exit("Wrong argument");
	if (sec_arr_len(s) == 4)
		info->t_l->colors = get_arg_color(s[3]);
}

void	ft_light_add(t_info *info, t_l *light)
{
	t_l	*tmp;

	if (!info->t_l)
		info->t_l = light;
	else
	{
		tmp = info->t_l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = light;
		light->prev = tmp;
	}
}

void	get_light(t_info *info, char **s)
{
	t_l	*light;

	light = ft_calloc(sizeof(t_l), 1);
	if (!light)
		error_exit("malloc error");
	if (sec_arr_len(s) != 3 && sec_arr_len(s) != 4)
		error_exit("Wrong argument");
	light->coor = get_arg_coor(s[1]);
	light->light_brightness_ratio = ft_atof(s[2]);
	if (check_range(1, light->light_brightness_ratio) == ERR)
		error_exit("Wrong argument");
	if (sec_arr_len(s) == 4)
		light->colors = get_arg_color(s[3]);
	light->next = 0;
	ft_light_add(info, light);
}

// void	get_obj(t_info *info, char **opt, t_type type)
// {
// 	t_objs *obj;
// 	t_list *new;

// 	obj = malloc(sizeof(t_objs));
// 	if (!obj)
// 		error_exit("malloc error");
// 	new = ft_lstnew(obj);
// 	ft_lstadd_back(&(info->t_objs), new);
// 	check_obj(obj, opt, type);
// }
