/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:54:05 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/28 21:13:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"

int	check_oper(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (SUCCESS);
		i++;
	}
	return (ERR);
}

/*
* print는 test용도라서 나중에 지움.
*/
void	print_a(t_a *a)
{
	printf("amb_light_ratio = %f\n", a->amb_light_ratio);
	printf("colors = %f %f %f\n", a->colors.x, a->colors.y, a->colors.z);
}

void	print_c(t_c *c)
{
	printf("coor = %f %f %f\n", c->coor.x, c->coor.y, c->coor.z);
	printf("normal = %f %f %f\n", c->normal.x, c->normal.y, c->normal.z);
	printf("fov = %d\n", c->fov);
}

void	print_l(t_l *l)
{
	printf("coor = %f %f %f\n", l->coor.x, l->coor.y, l->coor.z);
	printf("light_brightness_ratio = %f\n", l->light_brightness_ratio);
	printf("colors = %f %f %f\n", l->colors.x, l->colors.y, l->colors.z);
	if (l->next)
		print_l(l->next);
}

void	print_objs(t_list *objs)
{
	t_obj	*obj;

	obj = (t_obj *)objs->content;
	if (obj->type == PL)
	{
		printf("PL\n");
		printf("coor = %f %f %f\n", obj->coor.x, obj->coor.y, obj->coor.z);
		printf("normal = %f %f %f\n", obj->normal.x, obj->normal.y, obj->normal.z);
		printf("colors = %f %f %f\n", obj->colors.x, obj->colors.y, obj->colors.z);
	}
	if (obj->type == SP)
	{
		printf("SP\n");
		printf("coor = %f %f %f\n", obj->coor.x, obj->coor.y, obj->coor.z);
		printf("sphere_diameter = %f\n", obj->diameter);
		printf("colors = %f %f %f\n", obj->colors.x, obj->colors.y, obj->colors.z);
	}
	if (obj->type == CY)
	{
		printf("CY\n");
		printf("coor = %f %f %f\n", obj->coor.x, obj->coor.y, obj->coor.z);
		printf("normal = %f %f %f\n", obj->normal.x, obj->normal.y, obj->normal.z);
		printf("cylinder_diameter = %f\n", obj->diameter);
		printf("cylinder_height = %f\n", obj->cy_hei);
		printf("cylinder_colors = %f %f %f\n", obj->colors.x, obj->colors.y, obj->colors.z);
	}
	if (objs->next)
	{
		printf("\n");
		print_objs(objs->next);
	}
}

void	print_all_info(t_info *info)
{
	printf("info of a\n");
	print_a(&info->amb);
	printf("\n");

	printf("info of c\n");
	print_c(&info->cam);
	printf("\n");

	printf("info of l\n");
	print_l(info->lights);
	printf("\n");

	printf("info of objs\n");
	print_objs(info->objs);
}

void	printf_befor_after(t_info *info, t_info *rota)
{
	{
		printf("info of a\n");
		printf("amb_light_ratio = %f -> %f\n", info->amb.amb_light_ratio, rota->amb.amb_light_ratio);
		printf("colors = %f %f %f -> %f %f %f\n", info->amb.colors.x, info->amb.colors.y, info->amb.colors.z, rota->amb.colors.x, rota->amb.colors.y, rota->amb.colors.z);
		printf("\n");
	}

	{
		printf("info of c\n");
		printf("coor = %f %f %f -> %f %f %f\n", info->cam.coor.x, info->cam.coor.y, info->cam.coor.z, rota->cam.coor.x, rota->cam.coor.y, rota->cam.coor.z);
		printf("normal = %f %f %f -> %f %f %f\n", info->cam.normal.x, info->cam.normal.y, info->cam.normal.z, rota->cam.normal.x, rota->cam.normal.y, rota->cam.normal.z);
		printf("fov = %d -> %d\n", info->cam.fov, rota->cam.fov);
		printf("\n");
	}

	{
		t_l *tmp_a;
		t_l *tmp_b;
		tmp_a = info->lights;
		tmp_b = rota->lights;
		while (tmp_a)
		{
			printf("info of l\n");
			printf("coor = %f %f %f -> %f %f %f\n", tmp_a->coor.x, tmp_a->coor.y, tmp_a->coor.z, tmp_b->coor.x, tmp_b->coor.y, tmp_b->coor.z);
			printf("light_brightness_ratio = %f -> %f\n", tmp_a->light_brightness_ratio, tmp_b->light_brightness_ratio);
			printf("colors = %f %f %f -> %f %f %f\n", tmp_a->colors.x, tmp_a->colors.y, tmp_a->colors.z, tmp_b->colors.x, tmp_b->colors.y, tmp_b->colors.z);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}

	{
		printf("info of objs\n");

		t_obj	*obj_a;
		t_obj	*obj_b;
		obj_a = (t_obj*)info->objs->content;
		obj_b = (t_obj*)rota->objs->content;

		while (obj_a)
		{
			if (obj_a->type == PL)
			{
				printf("PL\n");
				printf("coor = %f %f %f -> %f %f %f\n", obj_a->coor.x, obj_a->coor.y, obj_a->coor.z, obj_b->coor.x, obj_b->coor.y, obj_b->coor.z);
				printf("normal = %f %f %f -> %f %f %f\n", obj_a->normal.x, obj_a->normal.y, obj_a->normal.z, obj_b->normal.x, obj_b->normal.y, obj_b->normal.z);
				printf("colors = %f %f %f -> %f %f %f\n", obj_a->colors.x, obj_a->colors.y, obj_a->colors.z, obj_b->colors.x, obj_b->colors.y, obj_b->colors.z);
			}
			if (obj_a->type == SP)
			{
				printf("SP\n");
				printf("coor = %f %f %f -> %f %f %f\n", obj_a->coor.x, obj_a->coor.y, obj_a->coor.z, obj_b->coor.x, obj_b->coor.y, obj_b->coor.z);
				printf("sphere_diameter = %f -> %f\n", obj_a->diameter, obj_b->diameter);
				printf("colors = %f %f %f -> %f %f %f\n", obj_a->colors.x, obj_a->colors.y, obj_a->colors.z, obj_b->colors.x, obj_b->colors.y, obj_b->colors.z);
			}
			if (obj_a->type == CY)
			{
				printf("CY\n");
				printf("coor = %f %f %f -> %f %f %f\n", obj_a->coor.x, obj_a->coor.y, obj_a->coor.z, obj_b->coor.x, obj_b->coor.y, obj_b->coor.z);
				printf("normal = %f %f %f -> %f %f %f\n", obj_a->normal.x, obj_a->normal.y, obj_a->normal.z, obj_b->normal.x, obj_b->normal.y, obj_b->normal.z);
				printf("cylinder_diameter = %f -> %f\n", obj_a->diameter, obj_b->diameter);
				printf("cylinder_height = %f -> %f\n", obj_a->cy_hei, obj_b->cy_hei);
				printf("cylinder_colors = %f %f %f -> %f %f %f\n", obj_a->colors.x, obj_a->colors.y, obj_a->colors.z, obj_b->colors.x, obj_b->colors.y, obj_b->colors.z);
			}
			obj_a = obj_a->next;
			obj_b = obj_b->next;
			printf("\n");
		}
	}
}
