/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:12 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 16:18:04 by seokchoi         ###   ########.fr       */
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
# define KEY_B		11
# define KEY_N		45
# define KEY_O		31

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
void		move_coordinate(t_vec3 *coor, int key);
void		key_hook_camera(t_window *win);
int			move_camera(int key, t_info *info);
void		key_hook_light(t_window *win, t_info *info);
void		convert_color(t_l *light, int curr);
void		select_light(int key, t_info *info);
void		move_light(int key, t_info *info);
void		light_selector();

#endif
