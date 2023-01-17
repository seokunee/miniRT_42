/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/17 14:16:41 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "stdio.h" // TODO 지우기

void	init_window(t_window *win)
{
	t_window	w;
	t_data		d;

	w = *win;
	d = w.data;
	w.mlx = mlx_init();
	mlx_get_screen_size(w.mlx, &w.width, &w.height);
	printf("width :%d heigth: %d\n", w.width, w.height);
	w.width /= 2;
	w.height /= 2;
	printf("width :%d heigth: %d\n", w.width, w.height);
	w.mlx_win = mlx_new_window(w.mlx, w.width, w.height, TITLE);
	d.img = mlx_new_image(w.mlx, w.width, w.height);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, \
	&d.endian);
	w.data = d;
	*win = w;
}
