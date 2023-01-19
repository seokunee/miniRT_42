/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:14:00 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/19 16:25:54 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <unistd.h>
# include <pthread.h>
# include "libft.h"
# include "info.h"
# include "window.h"

typedef struct s_drawer
{
	int			i;
	int			width;
	int			height;
	int			size;
	pthread_t	thread;
	t_data		data;
}	t_drawer;

void	start_drawing(t_window *win);

#endif
