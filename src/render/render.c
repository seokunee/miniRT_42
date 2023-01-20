/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:42 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 13:13:29 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/minirt.h"
#include "rt_math.h"
#include "info.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	draw_pixel(t_info **info, t_vec3 *pixel)
{
	t_ray	*pixel_ray;
	t_vec4	*mlx_pixel;
	int		pixel_color;

	pixel_ray = ft_malloc(sizeof(t_ray));
	pixel_ray->start = pixel;
	pixel_ray->dir = norm_3d_vec(v_sub(pixel, (*info)->t_c->coor));
	mlx_pixel = create_4d_vec_input_3d_vector(clamp_3d(trace_ray(info, pixel_ray, 5), 0.0f, 1.0f), 1.0f);
	pixel_color = create_trgb(mlx_pixel->x4, mlx_pixel->x1, mlx_pixel->x2, mlx_pixel->x3);
	free_ray(pixel_ray);
	free(mlx_pixel);
	return (pixel_color);
}

int	calculate_pixel_color(t_info *info, int x, int y)
{
	t_vec2	pos;
	t_vec3	pixel;
	int		pixel_color;

	pos = vec2((double)x, (double)y);
	pixel = transform_screen_to_world(info, pos);
	pixel_color = draw_pixel(info, pixel);
	free(pos);
	free(pixel);
	return (pixel_color);
}
