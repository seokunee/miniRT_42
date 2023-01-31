/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:44:28 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 11:43:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "parse.h"

static void	key_hook_arrows(int key, t_window *win)
{
	if (key == KEY_ARROW_LEFT)
		(void)win;
	else if (key == KEY_ARROW_RIGHT)
		(void)win;
	else if (key == KEY_ARROW_DOWN)
		(void)win;
	else if (key == KEY_ARROW_UP)
		(void)win;
	// render update
}

int	binding_key_events(int key, t_info *info)
{
	t_window	*win;

	win = &(info->win);
	// ft_printf("key - %d\n", key);
	if (key == KEY_ESC)
		exit_event(win);
	else if (key == KEY_1 && win->terminal.light_on == false)
		key_hook_camera(win);
	else if (key == KEY_2 && win->terminal.cam_on == false)
		key_hook_light(win, info);
	else if (win->terminal.cam_on && (key == KEY_Q || key == KEY_W || \
		key == KEY_A || key == KEY_S || key == KEY_Z || key == KEY_X))
		move_camera(key, info);
	else if (KEY_ARROW_LEFT <= key && key <= KEY_ARROW_UP)
		key_hook_arrows(key, win);
	return (0);
}
