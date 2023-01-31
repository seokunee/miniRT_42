/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/31 16:18:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static int	get_offset(t_data *data, int x, int y)
{
	const int	line_length = data->line_length;
	const int	bits_per_pixel = data->bits_per_pixel;

	return (y * line_length + x * (bits_per_pixel / 8));
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + get_offset(data, x, y);
	*(unsigned int *)dst = color;
}

/// @brief 한 픽셀에 대한 색상 정보
/// @param t Transparency 투명도, 0 불투명 ~ 255 투명함
/// @param r Red
/// @param g Green
/// @param b Blue
/// @return
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, \
unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	convert_color_light(t_l *light, int curr)
{
	int	idx;

	idx = 0;
	while (idx < curr)
	{
		light = light->next;
		idx++;
	}
	light->colors.x = 255.0 - light->colors.x;
	light->colors.y = 255.0 - light->colors.y;
	light->colors.z = 255.0 - light->colors.z;
}

void	convert_color_object(t_list *objs, int curr)
{
	int	idx;

	idx = 0;
	while (idx < curr)
	{
		objs = objs->next;
		idx++;
	}
	((t_obj *)(objs->content))->colors.x = \
		255.0 - ((t_obj *)(objs->content))->colors.x;
	((t_obj *)(objs->content))->colors.y = \
		255.0 - ((t_obj *)(objs->content))->colors.y;
	((t_obj *)(objs->content))->colors.z = \
		255.0 - ((t_obj *)(objs->content))->colors.z;
}
