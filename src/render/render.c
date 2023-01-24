/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:42 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/24 15:59:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
#include "raytracer.h"
#include "rt_math.h"
#include "info.h"
#include "ray.h"
#include "hit.h"

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

int		create_rgb(t_color3 *color)
{
	int r;
	int g;
	int b;

	r = (int)(255.999 * color->x);
	g = (int)(255.999 * color->y);
	b = (int)(255.999 * color->z);
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	calculate_pixel_color(t_info *info, int x, int y)
{
	double		uv[2];
	t_ray		ray;
	t_color3	pixel_color;

	pixel_color = color3(0, 0, 0);
	uv[0] = (double)x / (info->hei - 1);
	uv[1] = (double)y / (info->wid - 1);
	ray.orig = info->t_c.coor;
	ray.dir = vunit(v_minus(v_sum(v_sum(info->t_c.left_bottom, v_mul_double(info->t_c.horizontal, uv[1])), v_mul_double(info->t_c.vertical, uv[0])), info->t_c.coor));
	pixel_color = v_sum(pixel_color, ray_color_preview(ray, info, 1));
	pixel_color = v_sum(pixel_color, v_mul_double(v_divide(info->t_a.colors, 255.0), info->t_a.amb_light_ratio));
	// filter(&pixel_color, info);
	pixel_color = vmin(pixel_color, vec3(1.0, 1.0, 1.0));
	return (create_rgb(&pixel_color));
}

t_color3	ray_color_preview(t_ray *r, t_info *info, int light_on)
{
	t_hit_record	rec;

	rec.tmin = 0.0001;
	rec.tmax = INFINITY;
	if (hit(info->t_objs, r, &rec))
	{
		// if (light_on == 0)
		// 	return (direct_lighting(info->t_l, r, &rec));
		// else
		// 	return (rec.texture->albedo1);
		return (rec.texture->albedo1);
	}
	// else if (light_on == 0)
	// 	return (color_background(r, s, &rec));
	else
		return (color3(0.5, 0.7, 1.0));
}

