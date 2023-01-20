/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:39:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 13:12:10 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
#define RAYTRACER_H

// #include "minirt.h"

t_vec3	*transform_screen_to_world(t_info **info, t_vec2 *screen);
t_hit	*find_closest_collision(t_info **info, t_ray *ray);
t_vec3	*trace_ray(t_info **info, t_ray *ray, const int recurse_level);
int		calculate_pixel_color(t_info **info, int x, int y);




#endif
