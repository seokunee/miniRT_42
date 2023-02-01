/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:04:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/01 13:24:41 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "rt_math.h"
#include <stdio.h>

static void	rotation_controler(void)
{
	const char	*orange = "\033[38;5;208m";

	printf("%s╔═══════════════════════════════════════════╗\n", orange);
	printf("║         CAMERA rotation controler         ║\n");
	printf("╠═══════╦═══════════════════════════════════╣\n");
	printf("║ PRESS ║              CONTROL              ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   ↑   ║           ROTATE Y AXIS           ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   ↓   ║           ROTATE -Y AXIS          ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   ←   ║           ROTATE -X AXIS          ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   →   ║           ROTATE X AXIS           ║\n");
	printf("╚═══════╩═══════════════════════════════════╝\n");
}

void	key_hook_camera(t_window *win)
{
	if (win->terminal.cam_on == false)
	{
		printf("╔═══════════════════════════════════════════╗\n");
		printf("║             CAMERA : TURN ON              ║\n");
		printf("╚═══════════════════════════════════════════╝\n");
		win->terminal.cam_on = true;
		remote_controler("CAMERA");
		rotation_controler();
		printf("To exit the camera controler, PRESS the 1 key\n");
	}
	else
	{
		print_turn_off("CAMERA");
		win->terminal.cam_on = false;
		terminal_prompt();
	}
}

void	move_camera(int key, t_info *info)
{
	t_info	rotate_info;

	move_coordinate(&(info->cam.coor), key);
	rotate(&rotate_info, info);
}

void	move_camera_rotation(int key, t_info *info)
{
	t_info	rotate_info;

	if (key == KEY_ARROW_DOWN)
		info->cam.normal.y -= 0.05;
	else if (key == KEY_ARROW_UP)
		info->cam.normal.y += 0.05;
	else if (key == KEY_ARROW_LEFT)
		info->cam.normal.x -= 0.05;
	else if (key == KEY_ARROW_RIGHT)
		info->cam.normal.x += 0.05;
	copy_vector_value(&(info->cam.normal), vunit(info->cam.normal));
	printf("1111\n");
	rotate(&rotate_info, info);
	printf("2222\n");
	copy_vector_value(&(info->cam.coor), rotate_info.cam.coor);
	printf("3333\n");
}
