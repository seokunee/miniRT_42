/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:42 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 15:17:20 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/minirt.h"
#include "raytracer.h"
#include "rt_math.h"
#include "info.h"
#include "ray.h"

int	create_trgb_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	draw_pixel(t_info *info, t_vec3 pixel)
{
	t_ray	pixel_ray;
	t_vec4	mlx_pixel;
	int		pixel_color;

	pixel_ray.orig = vec3(pixel.x, pixel.y, pixel.z);
	pixel_ray.dir = norm_3d_vec(v_minus(pixel, info->t_c.coor));
	// printf(" dir-> x : %f, y: %f, z:%f\n", pixel_ray.dir.x, pixel_ray.dir.y, pixel_ray.dir.z);
	mlx_pixel = vec4_input_3d(clamp_3d(trace_ray(info, pixel_ray, 5), 0.0f, 1.0f), 1.0f);
	pixel_color = create_trgb_int(mlx_pixel.x4, mlx_pixel.x1, mlx_pixel.x2, mlx_pixel.x3);
	// printf("%f, %f, %f, %f\n", mlx_pixel.x1, mlx_pixel.x2, mlx_pixel.x3, mlx_pixel.x4);
	return (pixel_color);
}

int	calculate_pixel_color(t_info *info, int x, int y)
{
	t_vec2	pos;
	t_vec3	pixel;
	int		pixel_color;

	pos = vec2((double)x, (double)y);
	pixel = transform_screen_to_world(info, pos);
	printf("x: %d, y: %d, pos.x: %f, pos.y: %f", x, y, pos.x, pos.y);
	pixel_color = draw_pixel(info, pixel);
	return (pixel_color);
}
