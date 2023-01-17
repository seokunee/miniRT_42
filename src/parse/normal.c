/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:46:53 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 20:57:57 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	*get_arg_normal(char *s)
{
	char	**tmp;
	float	normal[3];
	t_vec3	*vec3;

	tmp = ft_split(s, ',');
	if (sec_arr_len(tmp) != 3)
		error_exit("Wrong normal argument num");
	check_only_num(tmp, ".");
	normal[0] = ft_atof(tmp[0]);
	if (check_range(-1, normal[0]) == ERR)
		error_exit("Wrong argument");
	normal[1] = ft_atof(tmp[1]);
	if (check_range(-1, normal[1]) == ERR)
		error_exit("Wrong argument");
	normal[2] = ft_atof(tmp[2]);
	if (check_range(-1, normal[2]) == ERR)
		error_exit("Wrong argument");
	free_double_array((void**)tmp);
	vec3 = create_3d_vec(normal[0],normal[1], normal[2]);
	if (v_dot(vec3, vec3) != 1)
		error_exit("Wrong normal argument");
	return (vec3);
}