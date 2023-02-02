/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 17:32:08 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structs.h"
#include "rt_math.h"
#include "window.h"
#include <stdio.h>

static t_vec4	get_image_pixel_color(t_texture *texture, int x, int y)
{
	x = clamp_int(x, 0, texture->width - 1);
	y = clamp_int(y, 0, texture->height - 1);
	return get_v_color(*(int *)get_pixel(&texture->data, x, y));
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

t_vec3	get_texture_image_color(t_texture *texture, const t_vec2 uv)
{
	const double v = 1 - uv.y;
	const double x = uv.x * (texture->width - 1);
	const double y = uv.y * (texture->height - 1);
	t_vec4		color;

	color = get_v_color(*(int *)get_pixel(&texture->data, round(x), round(y)));
	return vec3(color.x2, color.x3, color.x4);
}
