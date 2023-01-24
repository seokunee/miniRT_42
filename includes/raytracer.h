/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:39:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/24 16:01:58 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <stdio.h>
# include "hit.h"
# include "ray.h"
# include "info.h"

t_vec3	transform_screen_to_world(t_info *info, t_vec2 screen);
t_hit	find_closest_collision(t_info *info, t_ray ray);
t_vec3	trace_ray(t_info *info, t_ray ray, const int recurse_level);
int		calculate_pixel_color(t_info *info, int x, int y);
// t_hit	check_ray_collision_sphere(t_ray ray, t_object *sphere);

#endif
