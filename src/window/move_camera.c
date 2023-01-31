/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:04:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/31 16:18:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"

void	key_hook_camera(t_window *win)
{
	if (win->terminal.cam_on == false)
	{
		ft_printf("╔═══════════════════════════════════════════╗\n");
		ft_printf("║             CAMERA : TURN ON              ║\n");
		ft_printf("╚═══════════════════════════════════════════╝\n");
		win->terminal.cam_on = true;
		remote_controler("CAMERA");
		ft_printf("To exit the camera controler, PRESS the 1 key\n");
	}
	else
	{
		print_turn_off("CAMERA");
		win->terminal.cam_on = false;
		terminal_prompt();
	}
}

int	move_camera(int key, t_info *info)
{
	t_info	rotate_info;

	move_coordinate(&(info->cam.coor), key);
	rotate(&rotate_info, info);
	start_drawing(&rotate_info);
	return (0);
}
