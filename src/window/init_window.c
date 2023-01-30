/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/30 14:30:12 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	init_window(t_window *win)
{
	win->mlx = mlx_init();
	// mlx_get_screen_size(win->mlx, &win->width, &win->height);
	win->width = 1200;
	win->height = 1200;
	// win->width = 2560;
	// win->height = 1400;
	win->width /= 2;
	win->height /= 2;
	win->x_scale = 2.0 / win->width;
	win->y_scale = 2.0 / win->height;
	win->aspect_ratio = (double)win->width / (double)win->height;
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, TITLE);
}
