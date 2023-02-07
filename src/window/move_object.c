/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:19:20 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/06 21:21:52 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "rt_math.h"

void	select_obj_on_key_b(int key, t_info *info)
{
	t_info	rotate_info;

	(void)key;
	if (info->win.terminal.curr_obj != 0)
	{
		info->win.terminal.curr_obj--;
		convert_color_object(info->objs, info->win.terminal.curr_obj + 1);
		convert_color_object(info->objs, info->win.terminal.curr_obj);
		rotate(&rotate_info, info);
	}
}

void	select_obj_on_key_n(int key, t_info *info)
{
	t_info	rotate_info;

	(void)key;
	if (info->win.terminal.curr_obj != info->num_ele.objs_count - 1)
	{
		info->win.terminal.curr_obj++;
		convert_color_object(info->objs, info->win.terminal.curr_obj - 1);
		convert_color_object(info->objs, info->win.terminal.curr_obj);
		rotate(&rotate_info, info);
	}
}

void	select_obj(int key, t_info *info)
{
	t_info		rotate_info;
	t_window	*win;

	win = &info->win;
	if (key == KEY_B)
		select_obj_on_key_b(key, info);
	else if (key == KEY_N)
		select_obj_on_key_n(key, info);
	else if (key == KEY_O)
	{
		convert_color_object(info->objs, win->terminal.curr_obj);
		rotate(&rotate_info, info);
		win->terminal.obj_select = true;
		remote_controler("Object");
		rotation_controler("OBJECT");
		printf("To exit the object controler, PRESS the 3 key\n");
	}
	else if (key == KEY_2)
	{
		convert_color_object(info->objs, info->win.terminal.curr_obj);
		rotate(&rotate_info, info);
		info->win.terminal.obj_select = false;
		info->win.terminal.obj_on = false;
		terminal_prompt();
	}
}

void	key_hook_obj(t_window *win, t_info *info)
{
	t_list	*obj;
	t_info	rotate_info;

	obj = info->objs;
	if (!obj)
		return ((void)printf("NO Object\n"));
	if (win->terminal.obj_on == false)
	{
		win->terminal.obj_on = true;
		obj_selector();
		convert_color_object(obj, win->terminal.curr_obj);
		rotate(&rotate_info, info);
		convert_color_object(rotate_info.objs, win->terminal.curr_obj);
	}
	else
	{
		win->terminal.obj_on = false;
		win->terminal.obj_select = false;
		win->terminal.curr_obj = 0;
		print_turn_off("OBJECT");
		start_drawing(info);
		terminal_prompt();
	}
}

void	move_objs(int key, t_info *info)
{
	t_info	rotate_info;
	t_list	*curr_objs;
	int		idx;

	idx = -1;
	curr_objs = info->objs;
	while (++idx < info->win.terminal.curr_obj)
		curr_objs = curr_objs->next;
	move_coordinate(&((t_obj *)(curr_objs->content))->coor, key);
	if (key == KEY_3)
	{
		info->win.terminal.obj_on = false;
		info->win.terminal.obj_select = false;
		info->win.terminal.curr_obj = 0;
		print_turn_off("OBJECT");
		start_drawing(info);
		terminal_prompt();
	}
	rotate(&rotate_info, info);
}
