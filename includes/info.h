/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 21:33:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
#define INFO_H

#include "minirt.h"

#define ERR 1
#define SUCCESS 0

typedef struct s_objs t_objs;

/*
* Ambient lightning:
* identifier: A
* ambient lighting ratio in range [0.0,1.0]: 0.2
* R,G,B colors in range [0-255]: 255, 255, 255
*/
typedef struct s_a
{
	//char			*identifier;	// 일단 넣어봤는데, 없어도 될것같습니다.
	float			amb_light_ratio;
	t_vec3	*colors;
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
	// char			*identifier;
	t_vec3	*coor;
	t_vec3	*normal;
	int				fov;
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
	t_vec3	*coor;
	float			light_brightness_ratio;
	/* unsued in mand part */
	t_vec3	*colors;
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
	t_vec3	*coor;
	t_vec3	*normal;
	t_vec3	*colors;
	float			cylinder_diameter;
	float			cylinder_height;
}	t_cy;

/*
* PL : Plane
* SP : Sphere
* CY : Cylinder
*/
typedef enum e_type
{
	NO_OBJS,
	PL,
	SP,
	CY,
}	t_type;

/*
* Objs:
* identifier : objs type
* x,y,z coordinates: 50.0,0.0,20.6
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* the cylinder diameter: 14.2
* the cylinder height: 21.42
* R,G,B colors in range [0,255]: 10, 0, 255
*/
struct s_objs
{
	enum e_type		type;
	t_vec3	*coor;
	t_vec3	*normal;
	float	diameter;
	float	cy_hei;
	t_vec3	*colors;
	t_objs	*next;
	t_objs	*prev;
};

/*
* info
*/
typedef struct s_info
{
	struct s_a	*t_a;
	struct s_c	*t_c;
	struct s_l	*t_l;
	t_list		*t_objs;
	int 		wid;
	int 		hei;
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

#endif
