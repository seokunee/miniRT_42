/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:04:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/01 21:20:06 by chanwjeo         ###   ########.fr       */
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

void	test(t_info *rotate, t_vec3 normal)
{
	const t_vec3	dir_z = vec3(normal.x, normal.y, normal.z);
	const t_vec3	dir_y = v_cross(dir_z, vec3(0, 0, 1));
	const t_vec3	dir_x = v_cross(dir_y, dir_z);
	t_list			*rotate_list;
	t_obj			*rotate_obj;

	rotate_list = rotate->objs;
	while (rotate_list)
	{
		rotate_obj = (t_obj *)(rotate_list->content);
		copy_vector_value(&(rotate_obj->coor), vec3(\
			v_element_sum(v_mul(dir_x, rotate_obj->coor)),
			v_element_sum(v_mul(dir_y, rotate_obj->coor)),
			v_element_sum(v_mul(dir_z, rotate_obj->coor))));
		copy_vector_value(&(rotate_obj->normal), vec3(\
			v_element_sum(v_mul(dir_x, rotate_obj->normal)),
			v_element_sum(v_mul(dir_y, rotate_obj->normal)),
			v_element_sum(v_mul(dir_z, rotate_obj->normal))));
		rotate_list = rotate_list->next;
	}
}

void	move_camera_rotation(int key, t_info *info)
{
	double radian;
	double sin_theta;
	double cos_theta;
	t_vec3	dir_x;
	t_vec3	dir_y;
	t_vec3	dir_z;

	if (key == KEY_ARROW_RIGHT)
	{
		radian = degrees_to_radians_double(15);
		sin_theta = sin(radian);
		cos_theta = cos(radian);
		dir_x = vec3(cos_theta, 0, sin_theta);
		dir_y = vec3(0, 1, 0);
		dir_z = vec3(-sin_theta, 0, cos_theta);
		t_list *objs = info->objs;
		int idx = -1;
		while (++idx < info->num_ele.objs_count)
		{
			copy_vector_value(&(((t_obj *)(objs->content))->coor),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->coor))));
			copy_vector_value(&(((t_obj *)(objs->content))->normal),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->normal))));
			objs = objs->next;
		}
		t_l *light = info->lights;
		idx = -1;
		while (++idx < info->num_ele.l_count)
		{
			copy_vector_value(&(light->coor),
				vec3(v_element_sum(v_mul(dir_x, light->coor)), \
					v_element_sum(v_mul(dir_y, light->coor)), \
					v_element_sum(v_mul(dir_z, light->coor))));
			light = light->next;
		}
	}
	else if (key == KEY_ARROW_LEFT)
	{
		radian = degrees_to_radians_double(15);
		sin_theta = sin(-radian);
		cos_theta = cos(-radian);
		dir_x = vec3(cos_theta, 0, sin_theta);
		dir_y = vec3(0, 1, 0);
		dir_z = vec3(-sin_theta, 0, cos_theta);
		t_list *objs = info->objs;
		int idx = -1;
		while (++idx < info->num_ele.objs_count)
		{
			copy_vector_value(&(((t_obj *)(objs->content))->coor),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->coor))));
			copy_vector_value(&(((t_obj *)(objs->content))->normal),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->normal))));
			objs = objs->next;
		}
		t_l *light = info->lights;
		idx = -1;
		while (++idx < info->num_ele.l_count)
		{
			copy_vector_value(&(light->coor),
				vec3(v_element_sum(v_mul(dir_x, light->coor)), \
					v_element_sum(v_mul(dir_y, light->coor)), \
					v_element_sum(v_mul(dir_z, light->coor))));
			light = light->next;
		}
	}
	else if (key == KEY_ARROW_UP)
	{
		radian = degrees_to_radians_double(15);
		sin_theta = sin(-radian);
		cos_theta = cos(-radian);
		dir_x = vec3(1, 0, 0);
		dir_y = vec3(0, cos_theta, -sin_theta);
		dir_z = vec3(0, sin_theta, cos_theta);
		t_list *objs = info->objs;
		int idx = -1;
		while (++idx < info->num_ele.objs_count)
		{
			copy_vector_value(&(((t_obj *)(objs->content))->coor),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->coor))));
			copy_vector_value(&(((t_obj *)(objs->content))->normal),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->normal))));
			objs = objs->next;
		}
		t_l *light = info->lights;
		idx = -1;
		while (++idx < info->num_ele.l_count)
		{
			copy_vector_value(&(light->coor),
				vec3(v_element_sum(v_mul(dir_x, light->coor)), \
					v_element_sum(v_mul(dir_y, light->coor)), \
					v_element_sum(v_mul(dir_z, light->coor))));
			light = light->next;
		}
	}
	else if (key == KEY_ARROW_DOWN)
	{
		radian = degrees_to_radians_double(15);
		sin_theta = sin(radian);
		cos_theta = cos(radian);
		dir_x = vec3(1, 0, 0);
		dir_y = vec3(0, cos_theta, -sin_theta);
		dir_z = vec3(0, sin_theta, cos_theta);
		t_list *objs = info->objs;
		int idx = -1;
		while (++idx < info->num_ele.objs_count)
		{
			copy_vector_value(&(((t_obj *)(objs->content))->coor),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->coor)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->coor))));
			copy_vector_value(&(((t_obj *)(objs->content))->normal),
				vec3(v_element_sum(v_mul(dir_x, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_y, ((t_obj *)(objs->content))->normal)), \
					v_element_sum(v_mul(dir_z, ((t_obj *)(objs->content))->normal))));
			objs = objs->next;
		}
		t_l *light = info->lights;
		idx = -1;
		while (++idx < info->num_ele.l_count)
		{
			copy_vector_value(&(light->coor),
				vec3(v_element_sum(v_mul(dir_x, light->coor)), \
					v_element_sum(v_mul(dir_y, light->coor)), \
					v_element_sum(v_mul(dir_z, light->coor))));
			light = light->next;
		}
	}
	start_drawing(info);
}
