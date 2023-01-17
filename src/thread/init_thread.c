/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/17 14:15:57 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	init_thread(int i, int size, t_thread *thread, t_info *info)
{
	thread->i = i;
	thread->size = size;
	// thread->width = info->win->width;
	// thread->height = info->win->height;
}

// thread마다 총 갯수만큼 증감하기
void	*thread_routine(void *data)
{
	int			x;
	int			y;
	t_thread	*thread;

	thread = (t_thread *)data;
	x = thread->i;
	while (x < thread->width)
	{
		y = 0;
		while (y < thread->height)
		{
			// render(info, x, y); 계산함수 호출
			y++;
		}
		x += thread->size;
	}
}

void	create_thread(t_info *info)
{
	const long	procs = sysconf(_SC_NPROCESSORS_ONLN);
	int			i;
	t_thread	*threads;
	t_thread	thread;

	threads = ft_malloc(sizeof(t_thread) * (procs + 1));
	i = 0;
	while (i < procs)
	{
		thread = threads[i];
		init_thread(i, procs, &thread, info);
		pthread_create(&thread.thread, NULL, thread_routine, &thread);
		i++;
	}
	i = 0;
	while (i < procs)
	{
		thread = threads[i];
		pthread_join(&thread.thread, NULL);
		i++;
	}
	free(threads);
}
