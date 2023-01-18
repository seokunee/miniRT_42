/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/17 17:05:38 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	init_thread(int i, int size, t_render *render, t_window *win)
{
	render->i = i;
	render->size = size;
	render->width = win->width;
	render->height = win->height;
	render->data = &win->data;
}

// thread마다 총 갯수만큼 증감하기
void	*thread_routine(void *data)
{
	int			x;
	int			y;
	t_render	*render;

	render = (t_render *)data;
	x = render->i;
	while (x < render->width)
	{
		y = 0;
		while (y < render->height)
		{
			// render(info, x, y); 계산함수 호출
			int color = create_trgb(255, 255, 0, 0);
			put_pixel(render->data, x, y, color);
			y++;
		}
		x += render->size;
	}
	return (NULL);
}

void	start_drawing(t_window *win)
{
	const long	procs = sysconf(_SC_NPROCESSORS_ONLN);
	int			i;
	t_render	*threads;
	t_render	thread;

	threads = ft_malloc(sizeof(t_render) * (procs + 1));
	i = 0;
	while (i < procs)
	{
		thread = threads[i];
		init_thread(i, procs, &thread, win);
		pthread_create(&thread.thread, NULL, thread_routine, &thread);
		i++;
	}
	i = 0;
	while (i < procs)
	{
		thread = threads[i];
		pthread_join(thread.thread, NULL);
		i++;
	}
	free(threads);
}
