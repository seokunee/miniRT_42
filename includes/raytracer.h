/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:39:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/28 14:48:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <stdio.h>
# include "structs.h"

t_ray	get_ray(t_vec3 start, t_vec3 dir);
t_point3	ray_at(t_ray ray, double t);
t_hit	get_hit(double d, t_vec3 point, t_vec3 normal);
int		calculate_pixel_color(t_info *info, int x, int y);
t_hit	check_ray_collision_sphere(t_ray ray, t_obj *sphere);
t_hit	check_ray_collision_cylinder(t_ray ray, t_obj *cylinder);
t_hit	check_ray_collision_plane(t_ray ray, t_obj *plane);

#endif
