/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_lighting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:49:31 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/24 15:58:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "info.h"
#include "rt_math.h"

// t_color3	direct_lighting(t_l *light, t_ray *r, t_hit_record *rec)
// {
// 	t_color3	light_color;
// 	t_l			*light_first;

// 	light_color = color3(0, 0, 0);
// 	light_first = light;
// 	while (light)
// 	{
// 		light_color = v_sum(light_color, direct_lighting_get(light_first,
// 													light->element, r, rec));
// 		light = light->next;
// 	}
// 	return (vmin(vmult_(light_color, albedo(rec)), color3(1, 1, 1)));
// }

// t_color3	direct_lighting_get(t_l *objs, t_l *light,
// 									t_ray *r, t_hit_record *rec)
// {
// 	if (light->type == POINT)
// 		return (direct_lighting_point(objs, light, r, rec));
// 	else if (light->type == PARALLEL)
// 		return (direct_lighting_parallel(objs, light, r, rec));
// 	return (color3(0, 0, 0));
// }