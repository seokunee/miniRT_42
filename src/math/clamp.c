/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:40:45 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/21 23:25:23 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

// t_vec2	clamp_2d(t_vec2 v, double min_val, double max_val)
// {
//   return (vec2(min_double(max_double(v.x, min_val), max_val), min_double(max_double(v.y, min_val), max_val)));
// }

t_vec3	clamp_3d(t_vec3 v, double min_val, double max_val)
{
	return (vec3(min_double(max_double(v.x, min_val), max_val), \
	min_double(max_double(v.y, min_val), max_val), \
	min_double(max_double(v.z, min_val), max_val)));
}

// t_vec4	clamp_4d(t_vec4 v, double min_val, double max_val)
// {
//   return (vec4(min_double(max_double(v.x1, min_val), max_val), min_double(max_double(v.x2, min_val), max_val), min_double(max_double(v.x3, min_val), max_val), min_double(max_double(v.x4, min_val), max_val)));
// }
