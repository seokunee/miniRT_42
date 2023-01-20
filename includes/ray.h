/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:38:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 10:42:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "raytracer.h"

typedef struct s_ray
{
	t_vec3	orig;	//point
	t_vec3	dir;
	float	tm;
}	t_ray;

t_vec3	create_ray(t_vec3 *ori, t_vec3 *dir, float t);
t_ray	get_ray(t_cam cam, double s, double t);
t_vec3	ray_at(t_ray *ray, float t);

#endif
