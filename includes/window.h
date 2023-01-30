/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:12 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/30 16:40:40 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "mlx.h"
# include "structs.h"
# define TITLE "Hello miniRT!"

void	init_window(t_window *win);
void	binding_events(t_window *win);
int		binding_key_events(int key, t_window *win);
int		binding_mouse_events(int button, int x, int y, t_window *win);
int		exit_event(t_window *win);
void	put_pixel(t_data *data, int x, int y, int color);
int		get_color(t_vec3 vec);
t_vec3	white_v3(void);
t_vec3	black_v3(void);

#endif
