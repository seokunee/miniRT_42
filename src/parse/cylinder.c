/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 09:41:58 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include "info.h"

void	set_cy(t_objs *obj, char **opt)
{
	if (sec_arr_len(opt) != 6)
		error_exit("Wrong cylinder argument");
	check_coordinates(obj, opt[1]);
	obj->normal = get_arg_normal(opt[2]);
	check_diameter(obj, ft_atof(opt[3]));
	obj->cy_hei = ft_atof(opt[4]);
	if (obj->cy_hei <= 0)
	obj->colors = get_arg_color(opt[5]);
}
