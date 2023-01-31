/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:12 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 11:36:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "mlx.h"
# include "structs.h"
# define TITLE "Hello miniRT!"
# define KEY_ESC 53
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_UP 126
# define KEY_1		18
# define KEY_2		19
# define KEY_Q		12
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_Z		6
# define KEY_X		7

void		init_window(t_window *win);
void		binding_events(t_info *info);
int			binding_key_events(int key, t_info *info);
int			binding_mouse_events(int button, int x, int y, t_window *win);
int			exit_event(t_window *win);
void		put_pixel(t_data *data, int x, int y, int color);
int			get_color(t_vec3 vec);
t_color3	white_v3(void);
t_color3	black_v3(void);
void		terminal_prompt();
void		remote_controler(char *input);
void		key_hook_camera(t_window *win);
int			move_camera(int key, t_info *info);

#endif
