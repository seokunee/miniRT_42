/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:04:42 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/23 23:01:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
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

// static void	pixel_put_preview(t_scene *s, t_ray *r, int *i, t_bool light_on)
// {
// 	double			uv[2];
// 	t_color3		pixel_color;

// 	pixel_color = color3(0, 0, 0);
// 	uv[0] = (double)i[0] / (s->canv.height - 1);
// 	uv[1] = (double)i[1] / (s->canv.width - 1);
// 	r->orig = s->cam_onair->orig;
// 	r->dir = vunit(vminus(vplus(vplus(s->cam_onair->left_bottom,
// 				vmult(s->cam_onair->horizontal, uv[1])),
// 				vmult(s->cam_onair->vertical, uv[0])), s->cam_onair->orig));
// 	pixel_color = vplus(pixel_color, ray_color_preview(r, s, light_on));
// 	pixel_color = vplus(pixel_color, s->global.ambient);
// 	filter(&pixel_color, &s->global);
// 	my_mlx_pixel_put(s->img, i[1], s->canv.height - i[0] - 1,
// 									create_rgb(&pixel_color));
// }

int	calculate_pixel_color(t_info *info, int x, int y)
{
	// t_vec2	pos;
	// t_vec3	pixel;
	// int		pixel_color;
	double	uv[2];

	uv[0] = (double)i[0] / ()



	pos = vec2((double)x, (double)y);

	pixel = transform_screen_to_world(info, pos);
	// printf("pixel - [%f, %f, %f]\n", pixel.x, pixel.y, pixel.z);
	pixel_color = draw_pixel(info, pixel);
	return (pixel_color);
}
