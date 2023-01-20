/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:14:00 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/20 14:25:01 by seokchoi         ###   ########.fr       */
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
	struct s_info	*info;
}	t_drawer;

void	start_drawing(struct s_info *info);

#endif
