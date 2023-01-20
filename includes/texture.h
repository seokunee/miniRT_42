/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 16:59:27 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "minirt.h"
# include "info.h"
# include "rt_math.h"

typedef struct s_color
{
	int	tmp;
}	t_color;

typedef struct s_perlin
{
	int	tmp;
}	t_perlin;

typedef struct s_texture
{
	char			*type;
	t_color			color_value;
	t_color			even;
	t_color			odd;
	t_perlin		noise;
	double			scale;
	unsigned char	*data;
	int				wid;
	int				hei;
	int				byte_per_scanline;
}	t_texture;

#endif
