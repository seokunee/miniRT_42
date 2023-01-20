/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:48:21 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/20 12:39:45 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include "info.h"
// #include "rt_math.h"

void	get_ambient(t_info *info, char **s)
{
	if (sec_arr_len(s) != 3)
		error_exit("Wrong ambient argument");
	check_only_num1(s[1], ".");
	info->t_a.amb_light_ratio = ft_atof(s[1]);
	if (check_range(1, info->t_a.amb_light_ratio) == ERR)
		error_exit("Wrong argument:A:amb_L");
	info->t_a.colors = get_arg_color(s[2]);
}
