/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 18:27:53 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	init_window(t_window *win)
{
	win->mlx = mlx_init();
	win->width = 1200;
	win->height = 1200;
	win->width /= 2;
	win->height /= 2;
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, TITLE);
	win->terminal.prompt = false;
	win->terminal.cam_on = false;
	win->terminal.light_on = false;
	win->terminal.light_select = false;
	win->terminal.curr_light = 0;
}
