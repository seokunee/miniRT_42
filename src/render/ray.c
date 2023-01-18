/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:43:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 12:55:58 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"

t_vec3	create_ray(t_vec3 ori, t_vec3 dir, float t)
{
	t_ray	ray;

	ray.orig = ori;
	ray.dir = dir;
	ray.tm = t;
	return (ray);
}

t_vec3	ray_at(t_ray ray, float t)
{
	return (v_sum(ray.orig, v_float_mul(ray.dir, t)));
}