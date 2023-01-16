/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 02:11:51 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	set_pl(t_objs *obj, char **opt)
{
	if (sec_arr_len(opt) != 4)
		error_exit("wrong argument");
	check_coordinates(obj, opt[1]);
	check_normal_vector(obj, opt[2]);
	obj->colors = get_arg_color(opt[3]);
}
