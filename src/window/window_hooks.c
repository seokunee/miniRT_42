/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:54:59 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/16 17:28:26 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "window.h"

#define ON_DESTROY 17

int	exit_event(t_window *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit(0);
	return (0);
}

void	binding_events(t_window *win)
{
	mlx_key_hook(win->mlx_win, binding_key_events, win);
	mlx_mouse_hook(win->mlx_win, binding_mouse_events, win);
	mlx_hook(win->mlx_win, ON_DESTROY, 0, exit_event, win);
}
