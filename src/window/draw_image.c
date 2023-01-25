/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/25 14:15:47 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, \
unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

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
