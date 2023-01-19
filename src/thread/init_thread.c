/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/19 20:50:35 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

static int	is_last_img(t_drawer *drawer)
{
	return (drawer->i == drawer->size - 1);
}

void	*thread_routine(void *data)
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
			// TODO render(info, x, y); 계산함수 호출
			color = create_trgb(0, 0, 200, 200);
			if (x == drawer->width - 1)
			{
				// color = create_trgb(0, 0, 0, 200);
			}
			put_pixel(&drawer->data, x, y, color);
			y++;
		}
		x++;
	}
	return (NULL);
}

void	create_thread(int i, int size, t_drawer *drawer, t_window *win)
{
	t_data	*d;

	drawer->i = i;
	drawer->size = size;
	drawer->width = win->width / size;
	drawer->height = win->height;
	d = &drawer->data;
	if (is_last_img(drawer))
		drawer->width += win->width - (win->width / size) * size;
	d->img = mlx_new_image(win->mlx, drawer->width, drawer->height);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
	&d->endian);
	pthread_create(&drawer->thread, NULL, thread_routine, drawer);
}

void	attach_thread(int width, t_drawer *drawer, t_window *win)
{
	pthread_join(drawer->thread, NULL);
	printf("i: %d width: %d\n", drawer->i, width);
	mlx_put_image_to_window(win->mlx, win->mlx_win, drawer->data.img, width, 0);
	mlx_destroy_image(win->mlx, drawer->data.img);
	free(drawer);
}

void	start_drawing(t_window *win)
{
	const int	procs = sysconf(_SC_NPROCESSORS_ONLN);
	int			i;
	t_drawer	**drawers;

	drawers = ft_malloc(sizeof(t_drawer *) * (procs + 1));
	i = 0;
	while (i < procs)
	{
		drawers[i] = ft_malloc(sizeof(t_drawer));
		create_thread(i, procs, drawers[i], win);
		i++;
	}
	i = 0;
	while (i < procs)
	{
		attach_thread(win->width / procs * i, drawers[i], win);
		i++;
	}
	free(drawers);
}
