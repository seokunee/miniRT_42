/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:12 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/24 10:29:01 by chanwjeo         ###   ########.fr       */
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
	int		width;
	int		height;
}	t_data;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	double	aspect_ratio;
}	t_window;

void	init_window(t_window *win);
void	binding_events(t_window *win);
int		binding_key_events(int key, t_window *win);
int		binding_mouse_events(int button, int x, int y, t_window *win);
int		exit_event(t_window *win);
// TODO trgb 함수는 static 함수화 생각할 것
int		create_trgb(unsigned char t, unsigned char r, unsigned char g, \
unsigned char b);
void	put_pixel(t_data *data, int x, int y, int color);

#endif
