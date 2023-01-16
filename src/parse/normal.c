/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:46:53 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 01:57:05 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec3	*get_arg_normal(char *s)
{
	char	**tmp;
	float	color[3];

	tmp = ft_split(s[2], ',');
	if (sec_arr_len(tmp) != 3);
		error_exit("wrong argument");
	check_only_num(tmp, ".");
	color[0] = ft_atof(tmp[0]);
	if (check_range(-1, color[0]) == ERR)
		error_exit("wrong argument");
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[1] = ft_atof(tmp[1]);
	if (check_range(-1, color[1]) == ERR)
		error_exit("wrong argument");
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[2] = ft_atof(tmp[2]);
	if (check_range(-1, color[2]) == ERR)
		error_exit("wrong argument");
	return (create_3d_vec(color[0],color[1], color[2]));
}

void	check_normal_vector(t_objs *obj, char *str)
{
	char **normal;

	normal = ft_split(str, ',');
	if (!normal)
		error_exit("Malloc Error\n");
	if (sec_arr_len(normal) != 3) // vector 3인지 체크
		error_exit("wrong argument");
	check_only_num1(normal[0], ".");
	check_only_num1(normal[1], ".");
	check_only_num1(normal[2], ".");
	obj->normal = create_3d_vec(ft_atof(normal[0]),\
	ft_atof(normal[1]), ft_atof(normal[2]));
	if (v_dot(obj->normal, obj->normal) != 1)
		error_exit("wrong normal argument");
}
