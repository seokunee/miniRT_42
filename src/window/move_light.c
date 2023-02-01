/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:19:20 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/31 15:55:0 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "rt_math.h"

void	select_light_on_key_b(int key, t_info *info)
{
	t_info	rotate_info;

	if (info->win.terminal.curr_light != 0)
	{
		info->win.terminal.curr_light--;
		convert_color_light(info->lights, info->win.terminal.curr_light + 1);
		convert_color_light(info->lights, info->win.terminal.curr_light);
		rotate(&rotate_info, info);
	}
}

void	select_light_on_key_n(int key, t_info *info)
{
	t_info	rotate_info;

	if (info->win.terminal.curr_light != info->num_ele.l_count - 1)
	{
		info->win.terminal.curr_light++;
		convert_color_light(info->lights, info->win.terminal.curr_light - 1);
		convert_color_light(info->lights, info->win.terminal.curr_light);
		rotate(&rotate_info, info);
	}
}

void	select_light(int key, t_info *info)
{
	t_info	rotate_info;
	t_window	*win;

	win = &info->win;
	if (key == KEY_B)
		select_light_on_key_b(key, info);
	else if (key == KEY_N)
		select_light_on_key_n(key, info);
	else if (key == KEY_O)
	{
		convert_color_light(info->lights, info->win.terminal.curr_light);
		rotate(&rotate_info, info);
		win->terminal.light_select = true;
		remote_controler("Light ");
	}
	else if (key == KEY_2)
	{
		convert_color_light(info->lights, info->win.terminal.curr_light);
		rotate(&rotate_info, info);
		info->win.terminal.light_select = false;
		info->win.terminal.light_on = false;
		terminal_prompt();
	}
}

void	key_hook_light(t_window *win, t_info *info)
{
	t_l		*light;
	t_info	rotate_info;

	light = info->lights;
	if (!light)
		return ((void)printf("NO Light\n"));
	if (win->terminal.light_on == false)
	{
		info->win.terminal.light_on = true;
		light_selector();
		convert_color_light(light, win->terminal.curr_light);
		rotate(&rotate_info, info);
		convert_color_light(rotate_info.lights, win->terminal.curr_light);
	}
	else
	{
		info->win.terminal.light_on = false;
		info->win.terminal.light_select = false;
		info->win.terminal.curr_light = 0;
		print_turn_off("LIGHTS");
		start_drawing(info);
		terminal_prompt();
	}
}

void	move_light(int key, t_info *info)
{
	t_info	rotate_info;
	t_l		*curr_light;
	int		idx;

	idx = -1;
	curr_light = info->lights;
	while (++idx < info->win.terminal.curr_light)
		curr_light = curr_light->next;
	move_coordinate(&(curr_light->coor), key);
	if (key == KEY_2)
	{
		info->win.terminal.light_on = false;
		info->win.terminal.light_select = false;
		info->win.terminal.curr_light = 0;
		print_turn_off("LIGHTS");
		start_drawing(info);
		terminal_prompt();
	}
	rotate(&rotate_info, info);
}
