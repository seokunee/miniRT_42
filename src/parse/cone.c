/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/28 12:50:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"
#include "rt_math.h"

void	set_cn(t_obj *obj, char **opt)
{
	if (sec_arr_len(opt) != 6)
		error_exit("Wrong cone argument");
	check_coordinates(obj, opt[1]);
	obj->normal = get_arg_normal(opt[2]);
	check_diameter(obj, ft_atod(opt[3]));
	obj->cy_hei = ft_atod(opt[4]);
	if (obj->cy_hei <= 0)
		error_exit("Wrong cone argument");
	obj->colors.x = get_arg_color(opt[5]).x;
	obj->colors.y = get_arg_color(opt[5]).y;
	obj->colors.z = get_arg_color(opt[5]).z;
}
