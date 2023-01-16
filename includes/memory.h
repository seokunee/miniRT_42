/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:43:38 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 08:53:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
#define MEMORY_H

#include "minirt.h"

/*
* Allocated memory free functions
*/
void	free_vec_2d(t_vec2 *v);
void	free_vec_3d(t_vec3 *v);
void	free_vec_4d(t_vec4 *v);

void	free_raytracer(t_raytracer *rt);	// 이건 보완이 필요함
void	free_ray(t_ray *ray);
void	free_hit(t_hit *hit);
void	free_tri(t_tri *tri);

#endif
