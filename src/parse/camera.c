/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:03:23 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/19 08:41:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
#include "parse.h"
#include "info.h"

void	get_camera(t_info *info, char **s)
{
	if (sec_arr_len(s) != 4)
		error_exit("Wrong camera argument num");
	info->t_c->coor = get_arg_coor(s[1]);
	info->t_c->normal = get_arg_normal(s[2]);
	check_only_num1(s[3], "");
	info->t_c->fov = atoi(s[3]);
	if (check_range(180, info->t_c->fov) == ERR)
		error_exit("Wrong camera fov argument");
}
