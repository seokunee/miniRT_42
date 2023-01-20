/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:54:05 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/20 12:54:32 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
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
	t_objs *obj;

	obj = (t_objs *)objs->content;
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
	print_a(&info->t_a);
	printf("\n");

	printf("info of c\n");
	print_c(&info->t_c);
	printf("\n");

	printf("info of l\n");
	print_l(info->t_l);
	printf("\n");

	printf("info of objs\n");
	print_objs(info->t_objs);
	
	printf("\n");
	printf("window width  = %d\n", info->wid);
	printf("window height = %d\n", info->hei);
}