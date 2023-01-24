/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/24 09:28:23 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	init_window(t_window *win)
{
	// win->mlx = mlx_init();
	// mlx_get_screen_size(win->mlx, &win->width, &win->height);
	win->width = 200;
	win->height = 200;
	win->aspect_ratio = (double)(win->width) / (double)(win->height);
	// win->width /= 2;
	// win->height /= 2;
	// win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, TITLE);
}
