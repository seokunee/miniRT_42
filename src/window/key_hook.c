/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:44:28 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/16 17:25:38 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#define KEY_ESC 53
#define KEY_ARROW_LEFT 123
#define KEY_ARROW_RIGHT 124
#define KEY_ARROW_DOWN 125
#define KEY_ARROW_UP 126

static void	key_hook_arrows(int key, t_window *win)
{
	if (key == KEY_ARROW_LEFT)
		(void)win;
	else if (key == KEY_ARROW_RIGHT)
		(void)win;
	else if (key == KEY_ARROW_DOWN)
		(void)win;
	else if (key == KEY_ARROW_UP)
		(void)win;
	// render update
}

int	binding_key_events(int key, t_window *win)
{
	if (key == KEY_ESC)
		exit_event(win);
	else if (KEY_ARROW_LEFT <= key && key <= KEY_ARROW_UP)
		key_hook_arrows(key, win);
	return (0);
}
