/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:43:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 08:50:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"

t_vec3	*create_ray(t_vec3 *ori, t_vec3 *dir, float t)
{
	t_ray	*ray;

	ray = ft_malloc(sizeof(t_ray));
	ray->orig = create_3d_vec(ori->x, ori->y, ori->z);
	ray->dir = create_3d_vec(dir->x, dir->y, dir->z);
	ray->tm = t;
	free(ori);
	free(dir);
	return (ray);
}

t_vec3	*ray_at(t_ray *ray, float t)
{
	return (v_sum(ray->orig, v_float_mul(ray->dir, t)));
}