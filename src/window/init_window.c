/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/16 17:59:47 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	init_window(t_window *win)
{
	t_window	w;
	t_data		d;

	w = *win;
	d = w.data;
	w.mlx = mlx_init();
	mlx_get_screen_size(w.mlx, &w.sizex, &w.sizey);
	w.sizex /= 2;
	w.sizey /= 2;
	w.mlx_win = mlx_new_window(w.mlx, w.sizex, w.sizey, TITLE);
	d.img = mlx_new_image(w.mlx, w.sizex, w.sizey);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, \
	&d.endian);
	w.data = d;
	*win = w;
}
