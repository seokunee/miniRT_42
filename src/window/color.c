/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:08 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 14:55:05 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "rt_math.h"

static int	create_trgb(unsigned char t, unsigned char r, unsigned char g, \
unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	get_color(t_vec3 vec)
{
	t_color3	color;

	color = clamp_3d(vec, 0.0, 255.0);
	return (create_trgb(0, color.x, color.y, color.z));
}

t_color3	white_v3(void)
{
	return (vec3(255, 255, 255));
}

t_color3	black_v3(void)
{
	return (vec3(0, 0, 0));
}

t_vec4	get_v_color(int trgb)
{
	const int	t = ((trgb >> 24) & 0xFF);
	const int	r = ((trgb >> 16) & 0xFF);
	const int	g = ((trgb >> 8) & 0xFF);
	const int	b = ((trgb) & 0xFF);

	return (vec4(t, r, g, b));
}
