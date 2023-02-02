/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structs.h"
#include "rt_math.h"
#include "window.h"

static t_vec4	get_image_pixel_color(t_texture *texture, int x, int y)
{
	int	color;

	x = clamp_int(x, 0, texture->width - 1);
	y = clamp_int(y, 0, texture->height - 1);
	color = get_offset(&texture->data, x, y);
	return (get_v_color(color));
}

static t_vec4	get_clamped(t_texture *texture, int x, int y)
{
	t_vec4	point;

	x = clamp_int(x, 0, texture->width - 1);
	y = clamp_int(y, 0, texture->height - 1);
	point = get_image_pixel_color(texture, x, y);
	return (vec4(point.x1, point.x2 / 255.0, \
	point.x3 / 255.0, point.x3 / 255.0));
}

static t_vec4	get_clamped_raw(t_texture *texture, int x, int y)
{
	t_vec4	point;

	x = clamp_int(x, 0, texture->width - 1);
	y = clamp_int(y, 0, texture->height - 1);
	point = get_image_pixel_color(texture, x, y);
	return (vec4(point.x1, point.x2, point.x3, point.x4));
}

t_vec4	sample_point(t_texture *texture, const t_vec2 uv, int is_raw)
{
	t_vec3	xy;
	int		x;
	int		y;

	xy = vec3(uv.x * texture->width, uv.y * texture->height, 0.0);
	xy = v_sum_double(xy, -0.5, -0.5, -0.5);
	x = round(xy.x);
	y = round(xy.y);
	if (is_raw != true)
		return (get_clamped(texture, x, y));
	else
		return (get_clamped_raw(texture, x, y));
}
