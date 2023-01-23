/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/23 23:00:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include "raytracer.h"

static int	is_last_img(t_drawer *drawer)
{
	return (drawer->i == drawer->size - 1);
}

static void	*thread_routine(void *data)
{
	int			x;
	int			y;
	t_drawer	*drawer;
	int			color;

	drawer = (t_drawer *)data;
	x = 0;
	while (x < drawer->width)
	{
		y = 0;
		while (y < drawer->height)
		{
			color = calculate_pixel_color(drawer->info, x, y);
			put_pixel(&drawer->data, x, y, color);
			y++;
		}
		x++;
	}
	return (NULL);
}

static void	create_thread(int i, int size, t_drawer *drawer, t_info *info)
{
	t_data	*d;

	drawer->i = i;
	drawer->size = size;
	drawer->width = info->win.width / size;
	drawer->height = info->win.height;
	drawer->info = info;
	d = &drawer->data;
	if (is_last_img(drawer))
		drawer->width += info->win.width - (info->win.width / size) * size;
	d->img = mlx_new_image(info->win.mlx, drawer->width, drawer->height);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
	&d->endian);
	pthread_create(&drawer->thread, NULL, thread_routine, drawer);
}

static void	attach_thread(int width, t_drawer *drawer, t_window *win)
{
	pthread_join(drawer->thread, NULL);
	mlx_put_image_to_window(win->mlx, win->mlx_win, drawer->data.img, width, 0);
	mlx_destroy_image(win->mlx, drawer->data.img);
	free(drawer);
}

void	start_drawing(t_info *info)
{
	// const int	procs = sysconf(_SC_NPROCESSORS_ONLN);
	const int	procs = 1;

	int			i;
	t_drawer	**drawers;

	drawers = ft_malloc(sizeof(t_drawer *) * (procs + 1));
	i = 0;
	while (i < procs)
	{
		drawers[i] = ft_malloc(sizeof(t_drawer));
		create_thread(i, procs, drawers[i], info);
		i++;
	}
	i = 0;
	while (i < procs)
	{
		attach_thread(info->win.width / procs * i, drawers[i], &info->win);
		i++;
	}
	free(drawers);
}
