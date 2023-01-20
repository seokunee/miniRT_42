/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:30:20 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 21:36:53 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "rt_math.h"

t_color3	get_solid_color(t_texture *texture)
{
	t_color3	color;
	color = vec3(texture->color_value.x, texture->color_value.y, texture->color_value.z);
	return (color);
}

t_color3	get_
