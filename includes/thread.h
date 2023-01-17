/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:14:00 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/17 14:09:39 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <unistd.h>
# include <pthread.h>
# include "libft.h"
# include "info.h"

typedef struct s_thread
{
	int				i;
	int				width;
	int				height;
	int				size;
	pthread_attr_t	thread;
}	t_thread;

#endif
