/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:47:53 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 14:39:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	*get_arg_color(char *s)
{
	char	**tmp;
	float	color[3];

	tmp = ft_split(s, ',');
	if (sec_arr_len(tmp) != 3)
		error_exit("wrong argument");
	check_only_num(tmp, "");
	color[0] = ft_atof(tmp[0]);
	if (check_range(255, color[0]) == ERR)
		error_exit("wrong argument");
	color[1] = ft_atof(tmp[1]);
	if (check_range(255, color[1]) == ERR)
		error_exit("wrong argument");
	color[2] = ft_atof(tmp[2]);
	if (check_range(255, color[2]) == ERR)
		error_exit("wrong argument");
	return (create_3d_vec(color[0],color[1], color[2]));
}