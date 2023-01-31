/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:19:20 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/31 11:43:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"

void	key_hook_light(t_window *win, t_info *info)
{
	if (win->terminal.light_on == false)
	{
		ft_printf("╔═══════════════════════════════════════════╗\n");
		ft_printf("║              LIGHT : TURN ON              ║\n");
		ft_printf("╚═══════════════════════════════════════════╝\n");
		win->terminal.light_on = true;
		// remote_controler("LIGHT ");
		ft_printf("╔═══════════════════════════════════════════╗\n");
		ft_printf("║              LIGHT SELECTOR               ║\n");
		// while ()
		ft_printf("╚═══════════════════════════════════════════╝\n");
		// ft_printf("To exit the light controler, PRESS the 1 key\n");
	}
	else
	{
		ft_printf("╔═══════════════════════════════════════════╗\n");
		ft_printf("║              LIGHT : TURN OFF             ║\n");
		ft_printf("╚═══════════════════════════════════════════╝\n");
		win->terminal.light_on = false;
		terminal_prompt();
	}
}


int	move_camera(int key, t_info *info)
{
	t_info	rotate_info;

	if (key == KEY_Q)
		info->cam.coor.x -= 1;
	else if (key == KEY_W)
		info->cam.coor.x += 1;
	else if (key == KEY_A)
		info->cam.coor.y -= 1;
	else if (key == KEY_S)
		info->cam.coor.y += 1;
	else if (key == KEY_Z)
		info->cam.coor.z -= 1;
	else if (key == KEY_X)
		info->cam.coor.z += 1;
	rotate(&rotate_info, info);
	start_drawing(&rotate_info);
	return (0);
}
