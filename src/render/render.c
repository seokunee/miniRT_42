/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:42 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 09:54:28 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	draw_pixel(t_info *info, t_vec3 *pixel)
{
	t_ray	*pixel_ray;
	t_vec4	*mlx_pixel;

	pixel_ray = ft_malloc(sizeof(t_ray));
	pixel_ray->start = pixel;
	pixel_ray->dir = norm_3d_vec(v_sub(pixel, info->t_c->coor));
	mlx_pixel = create_4d_vec_input_3d_vector(clamp_3d(trace_ray(pixel_ray, 5), 0.0f, 1.0f), 1.0f);
	// draw;
	free_ray(pixel_ray);
	free(mlx_pixel);
}

void	render(t_info **info)
{
	int		w;
	int		h;
	t_vec2	*pos;
	t_vec3	*pixel;

	h = -1;
	while (++h < (*info)->hei)
	{
		w = -1;
		while (++w < (*info)->wid)
		{
			pos = create_2d_vec((float)w, (float)h);
			pixel = transform_screen_to_world(info, pos);
			draw_pixel(info, pixel);
			free(pos);
			free(pixel);
		}
	}
}
