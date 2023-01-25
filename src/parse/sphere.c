/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 12:51:17 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include "info.h"

void	set_sp(t_objs *obj, char **opt)
{
	if (sec_arr_len(opt) != 4)
		error_exit("Wrong argument");
	check_coordinates(obj, opt[1]);
	check_diameter(obj, ft_atod(opt[2]));
	obj->colors = get_arg_color(opt[3]);
}
