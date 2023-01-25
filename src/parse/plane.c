/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/25 17:39:37 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"

void	set_pl(t_obj *obj, char **opt)
{
	if (sec_arr_len(opt) != 4)
		error_exit("Wrong plane argument num");
	check_coordinates(obj, opt[1]);
	obj->normal = get_arg_normal(opt[2]);
	obj->colors = get_arg_color(opt[3]);
}
