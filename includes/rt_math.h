/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:29 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
#define RT_MATH_H

// #include "minirt.h"
#include <math.h>

typedef struct s_vec2 t_vec2;
typedef struct s_vec2 t_point2;
typedef struct s_vec2 t_color2;

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

typedef struct s_vec4 t_vec4;
typedef struct s_vec4 t_point4;
typedef struct s_vec4 t_color4;

struct s_vec2
{
	double	x;
	double	y;
} ;

struct s_vec3
{
	
	double	x;
	double	y;
	double	z;
} ;

struct s_vec4
{
	double	x1;
	double	x2;
	double	x3;
	double	x4;
} ;

/*
* '+', '*', '-' operator of vector
*/

/* vector Generator */
t_vec3	vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void	vset(t_vec3 *v, double x, double y, double z);

t_vec3	vplus(t_vec3 v1, t_vec3 v2);
t_vec3	vplus_double(t_vec3 v, double x, double y, double z);
t_vec3	v_minus(t_vec3 v1, t_vec3 v2);
t_vec3	v_minus_double(t_vec3 v, double x, double y, double z);
t_vec3	v_mul(t_vec3 v1, t_vec3 v2);
t_vec3	v_mul_double(t_vec3 v, double t);
t_vec3	v_divide(t_vec3 v, double t);
t_vec3      vunit(t_vec3 v);


// t_vec3	*vec_multiple(t_vec3 *v1, t_vec3 *v2);
// t_vec3	*vec_subtract(t_vec3 *v1, t_vec3 *v2);

/*

* Return a length of vector
*/
double	v_len(t_vec3 v);
/*

* dot and cross product of vector
*/
double	v_dot(t_vec3 v1, t_vec3 v2);
t_vec3	v_cross(t_vec3 v1, t_vec3 v2);

float	degrees_to_radians_float(float degrees);
double	degrees_to_radians_double(double degrees);

#endif
