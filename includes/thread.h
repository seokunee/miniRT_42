/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:14:00 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/20 17:06:44 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <unistd.h>
# include <pthread.h>
# include "info.h"

typedef struct s_drawer
{
	int			i;
	int			width;
	int			height;
	int			size;
	pthread_t	thread;
	t_data		data;
	t_info		*info;
}	t_drawer;

void	start_drawing(t_info *info);

#endif
