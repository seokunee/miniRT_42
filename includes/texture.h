/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 21:30:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "info.h"
#include "rt_math.h"

typedef struct s_texture
{
	char	*type;
	struct s_color	color_value;
	struct s_color	even;
	struct s_color	odd;
	struct s_perlin	noise;
	double			scale;
	unsigned char	*data;
	int				wid;
	int				hei;
	int				byte_per_scanline;
}	t_texture;