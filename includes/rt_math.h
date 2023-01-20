/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 14:26:06 by seokchoi         ###   ########.fr       */
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
t_vec2		vec2(double x, double y);
t_vec3		vec3(double x, double y, double z);
t_vec4		vec4(double x1, double x2, double x3, double x4);
t_vec4		vec4_input_3d(t_vec3 v, double x);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void		vset(t_vec3 *v, double x, double y, double z);

t_vec3	v_sum(t_vec3 v1, t_vec3 v2);
t_vec3	v_sum_double(t_vec3 v, double x, double y, double z);
t_vec3	v_change_minus(t_vec3 v1);
t_vec3	v_minus(t_vec3 v1, t_vec3 v2);
t_vec3	v_minus_double(t_vec3 v, double x, double y, double z);
t_vec3	v_mul(t_vec3 v1, t_vec3 v2);
t_vec3	v_mul_double(t_vec3 v, double t);
t_vec3	v_divide(t_vec3 v, double t);
t_vec3 	vunit(t_vec3 v);
t_vec3	norm_3d_vec(t_vec3 v);

float	min_float(float f1, float f2);
float	max_float(float f1, float f2);

// t_vec2	clamp_2d(t_vec2 v, float min_val, float max_val);
t_vec3	clamp_3d(t_vec3 v, float min_val, float max_val);
// t_vec4	clamp_4d(t_vec4 v, float min_val, float max_val);
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
