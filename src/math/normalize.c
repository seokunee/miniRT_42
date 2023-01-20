/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:10:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 14:12:52 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"

t_vec3	norm_3d_vec(t_vec3 v)
{
	return (vec3(v.x / v_len(v), v.y / v_len(v), v.z / v_len(v)));
}

t_vec3      vunit(t_vec3 v)
{
	double len = v_len(v);
	if (len == 0)
	{
		// printf("Error\n:Devider is 0");
		exit(0);
	}
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}