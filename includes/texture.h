/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/24 10:37:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "minirt.h"
# include "info.h"
# include "rt_math.h"
# include "window.h"

typedef int					t_tex_type;

# define SOLID 0
# define CHECKER 1
# define CHECKER_UV 2
# define RAINBOW 3
# define IMAGE 4
# define WAVE 5
typedef struct s_texture
{
	t_color3	albedo1;
	t_color3	albedo2;
	double		option1;
	t_data		*img;
	t_tex_type	type;
}	t_texture;


#endif
