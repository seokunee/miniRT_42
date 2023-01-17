/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:12 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/16 17:28:36 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "mlx.h"
# define TITLE "Hello miniRT!"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		sizex;
	int		sizey;
	t_data	data;
}	t_window;

void	init_window(t_window *win);
void	binding_events(t_window *win);
int		binding_key_events(int key, t_window *win);
int		binding_mouse_events(int button, int x, int y, t_window *win);
int		exit_event(t_window *win);

#endif
