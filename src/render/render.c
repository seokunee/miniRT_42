/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:42 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 17:23:34 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	draw_pixel(t_info *info, t_vec3 *pixel)
{
	t_ray	*pixel_ray;

	pixel_ray->start = pixel;
	pixel_ray->dir = 
}

void	render(t_info *info)
{
	int		w;
	int		h;
	t_vec2	*pos;
	t_vec3	*pixel;

	h = -1;
	while (++h < info->window->height)
	{
		w = -1;
		while (++w < info->window->width)
		{
			pos = create_2d_vec((float)w, (float)h);
			pixel = transform_screen_to_world(info, pos);
			draw_pixel(info, pixel);
			free(pos);
			free(pixel);
		}
	}
}