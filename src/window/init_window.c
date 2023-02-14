/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/07 13:08:11 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"

void	init_window(t_window *win)
{
	win->mlx = mlx_init();
	win->width = 600;
	win->height = 600;
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, TITLE);
	ft_memset(&win->terminal, 0, sizeof(win->terminal));
}
