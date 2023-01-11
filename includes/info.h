/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 16:17:24 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
#define INFO_H

#include "minirt.h"

/*
* Ambient lightning:
* identifier: A
* ambient lighting ratio in range [0.0,1.0]: 0.2
* R,G,B colors in range [0-255]: 255, 255, 255
*/
typedef struct s_a
{
	char	*identifier;	// 일단 넣어봤는데, 없어도 될것같습니다.
	float	amb_light_ratio;
	int		color_r;
	int		color_g;
	int		color_b;
	/* 위처럼 r, g, b 쓰거나 혹은 */
	int		colors[3];
}	t_a;

/*
* Camera:
* identifier: C
* x,y,z coordinates of the view point: 0.0,0.0,20.6
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* FOV : Horizontal field of view in degrees in range [0,180]
*/
typedef struct s_c
{
	// char		*identifier;
	float	coordinates[3];
	float	normalized_orientation[3];
	int		fov;
}	t_c;

/*
* Light:
* identifier: L
* x,y,z coordinates of the light point: 0.0,0.0,20.6
* the light brightness ratio in range [0.0,1.0]: 0.6
* (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/
typedef struct s_l
{
	float	coordinates[3];
	float	light_brightness_ratio;
	/* unsued in mand part */
	int		colors[3];
}	t_l;

/*
* Plane:
* identifier: pl
* x,y,z coordinates: 0.0,0.0,-10.0
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* R,G,B colors in range [0-255]: 0, 0, 255
*/
typedef struct s_pl
{
	float	coordinates[3];
	float	normalized_orientation[3];
	int		colors[3];
}	t_pl;

/*
* Sphere:
* identifier: sp
* x,y,z coordinates of the sphere center: 0.0,0.0,20.6
* the sphere diameter: 12.6
* R,G,B colors in range [0-255]: 10, 0, 255
*/
typedef struct s_sp
{
	float	coordinates[3];
	float	sphere_diameter;
	int		colors[3];
}	t_sp;

/*
* Cylinder:
* identifier: cy
* x,y,z coordinates: 50.0,0.0,20.6
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* the cylinder diameter: 14.2
* the cylinder height: 21.42
* R,G,B colors in range [0,255]: 10, 0, 255
*/
typedef struct s_cy
{
	float	coordinates[3];
	float	normalized_orientation[3];
	float	cylinder_diameter;
	float	cylinder_height;
	int		colors[3];
}	t_cy;

/*
* info
*/
typedef struct s_info
{
	struct s_a	*t_a;
	struct s_c	*t_c;
	struct s_l	*t_l;
	struct s_pl	*t_pl;
	struct s_sp	*t_sp;
	struct s_cy	*t_cy;
}	t_info;

/*
* check_flag
* explaination : check number of flags in '.rt file'
*/
typedef struct s_check_flag
{
	int	a;
	int	c;
	int	l;
	int	pl;
	int	sp;
	int	cy;
}	t_check_flag;

void	init_info(t_info *info);
char	*parse_rt_file(t_info *info, char *file_name);

#endif
