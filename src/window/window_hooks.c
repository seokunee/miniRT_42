/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:54:59 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 11:09:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "window.h"
#include "structs.h"

#define ON_DESTROY 17

int	exit_event(t_window *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit(0);
	return (0);
}

void	binding_events(t_info *info)
{
	t_window	*win;

	win = &(info->win);
	ft_printf("terminal->cam_on : %d\n", info->win.terminal.cam_on);
	ft_printf("terminal->light_on : %d\n", info->win.terminal.light_on);
	if (win->terminal.prompt == false)
	{
		win->terminal.prompt = true;
		terminal_prompt();
	}
	mlx_key_hook(win->mlx_win, binding_key_events, info);
	mlx_mouse_hook(win->mlx_win, binding_mouse_events, win);
	mlx_hook(win->mlx_win, ON_DESTROY, 0, exit_event, win);
}
