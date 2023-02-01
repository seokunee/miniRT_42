/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:04:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/01 16:27:04 by chanwjeo         ###   ########.fr       */
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
	t_list	*objs;
	t_l		*light;
	int		idx;

	if (key == KEY_Q)
	{
		idx = -1;
		objs = info->objs;
		while (++idx < info->num_ele.objs_count)
		{
			((t_obj *)(objs->content))->coor.x -= 1;
			objs = objs->next;
		}
		idx = -1;
		light = info->lights;
		while (++idx < info->num_ele.l_count)
		{
			light->coor.x -= 1;
			light = light->next;
		}
	}
	else if (key == KEY_W)
	{
		idx = -1;
		objs = info->objs;
		while (++idx < info->num_ele.objs_count)
		{
			((t_obj *)(objs->content))->coor.x += 1;
			objs = objs->next;
		}
		idx = -1;
		light = info->lights;
		while (++idx < info->num_ele.l_count)
		{
			light->coor.x += 1;
			light = light->next;
		}
	}
	else if (key == KEY_A)
	{
		idx = -1;
		objs = info->objs;
		while (++idx < info->num_ele.objs_count)
		{
			((t_obj *)(objs->content))->coor.y -= 1;
			objs = objs->next;
		}
		idx = -1;
		light = info->lights;
		while (++idx < info->num_ele.l_count)
		{
			light->coor.y -= 1;
			light = light->next;
		}
	}
	else if (key == KEY_S)
	{
		idx = -1;
		objs = info->objs;
		while (++idx < info->num_ele.objs_count)
		{
			((t_obj *)(objs->content))->coor.y += 1;
			objs = objs->next;
		}
		idx = -1;
		light = info->lights;
		while (++idx < info->num_ele.l_count)
		{
			light->coor.y += 1;
			light = light->next;
		}
	}
	else if (key == KEY_Z)
	{
		idx = -1;
		objs = info->objs;
		while (++idx < info->num_ele.objs_count)
		{
			((t_obj *)(objs->content))->coor.z -= 1;
			objs = objs->next;
		}
		idx = -1;
		light = info->lights;
		while (++idx < info->num_ele.l_count)
		{
			light->coor.z -= 1;
			light = light->next;
		}
	}
	else if (key == KEY_X)
	{
		idx = -1;
		objs = info->objs;
		while (++idx < info->num_ele.objs_count)
		{
			((t_obj *)(objs->content))->coor.z += 1;
			objs = objs->next;
		}
		idx = -1;
		light = info->lights;
		while (++idx < info->num_ele.l_count)
		{
			light->coor.z += 1;
			light = light->next;
		}
	}
	start_drawing(info);
}

void	move_camera_rotation(int key, t_info *info)
{
	t_info	rotate_info;
	t_list	*objs;
	int		idx;

	// rotate(&rotate_info, info);
	// idx = -1;
	// objs = info->objs;
	// while (++idx < 2)
	// {
	// 	printf("info.objs[%d] : [%f, %f, %f]\n", idx, ((t_obj *)(objs->content))->coor.x, ((t_obj *)(objs->content))->coor.y, ((t_obj *)(objs->content))->coor.z);
	// 	objs = objs->next;
	// }
	// if (key == KEY_ARROW_DOWN)
	// {
	// 	// info->cam.normal.y -= 0.05;
	// 	test(info, vunit(vec3(0, -0.05, 1)));
	// 	// const t_vec3	dir_z = vec3(info->cam.normal.x, info->cam.normal.y, info->cam.normal.z);
	// 	// const t_vec3	dir_y = v_cross(dir_z, vec3(0, 0, 1));
	// 	// const t_vec3	dir_x = v_cross(dir_y, dir_z);
	// }

	// start_drawing(info);
	idx = -1;
	objs = info->objs;
	while (++idx < 2)
	{
		printf("info.objs[%d] : [%f, %f, %f]\n", idx, ((t_obj *)(objs->content))->coor.x, ((t_obj *)(objs->content))->coor.y, ((t_obj *)(objs->content))->coor.z);
		objs = objs->next;
	}

	if (key == KEY_ARROW_DOWN)
		info->cam.normal.y -= 1;
	else if (key == KEY_ARROW_UP)
		info->cam.normal.y += 1;
	else if (key == KEY_ARROW_LEFT)
		info->cam.normal.x -= 1;
	else if (key == KEY_ARROW_RIGHT)
		info->cam.normal.x += 1;
	printf("1\n");
	copy_vector_value(&(info->cam.normal), vunit(info->cam.normal));
	printf("2\n");

	rotate(&rotate_info, info);
	printf("3\n");

	start_drawing(&rotate_info);
	printf("4\n");

	// printf("info->cam.coor = [%f, %f, %f]\n", info->cam.coor.x, info->cam.coor.y, info->cam.coor.z);
	// copy_vector_value(&(info->cam.normal), vunit(info->cam.normal));
	// printf("info->cam.normal = [%f, %f, %f]\n", info->cam.normal.x, info->cam.normal.y, info->cam.normal.z);
	idx = -1;
	objs = rotate_info.objs;
	while (++idx < 2)
	{
		printf("info.objs[%d] : [%f, %f, %f]\n", idx, ((t_obj *)(objs->content))->coor.x, ((t_obj *)(objs->content))->coor.y, ((t_obj *)(objs->content))->coor.z);
		objs = objs->next;
	}
	// rotate(&rotate_info, info);
	// printf("info->cam.normal = [%f, %f, %f]\n", info->cam.coor.x, info->cam.coor.y, info->cam.coor.z);
	// idx = -1;
	// objs = rotate_info.objs;
	// while (++idx < 2)
	// {
	// 	printf("rotate.objs[%d] : [%f, %f, %f]\n", idx, ((t_obj *)(objs->content))->coor.x, ((t_obj *)(objs->content))->coor.y, ((t_obj *)(objs->content))->coor.z);
	// 	objs = objs->next;
	// }
	// printf("rotate_info.cam.normal = [%f, %f, %f]\n", rotate_info.cam.normal.x, rotate_info.cam.normal.y, rotate_info.cam.normal.z);
	// copy_vector_value(&(info->cam).coor, rotate_info.cam.coor);
	// info->cam.coor.x = rotate_info.cam.coor.x;
	// info->cam.coor.y = rotate_info.cam.coor.y;
	// info->cam.coor.z = rotate_info.cam.coor.z;
	printf("3333\n");
}
