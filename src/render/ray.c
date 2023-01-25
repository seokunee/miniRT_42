/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:17:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/25 19:19:20 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

/// @brief
/// @param start start position of the ray
/// @param dir direction of the ray
/// @return
t_ray	get_ray(t_vec3 start, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = start;
	ray.normal = dir;
	return (ray);
}
