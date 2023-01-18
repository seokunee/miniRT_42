/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 13:20:18 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
#define RT_MATH_H

#include "minirt.h"
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

/*

* Create 3D-vector functions
* 1. Input 3 double values into arguments.
* 2. Input a double values into arguments.
	* Then, The vector will be returned that elements will get same value.
*/
t_vec3	*create_3d_vec(double f1, double f2, double f3);
t_vec3	*create_3d_vec_input_same_value(double f);

/*
* Create 4D-vector functions.
* 1. Input 3D-vector and a double value into arguments.
* 2. Input 4 double values into arguments.
* 3. Input a double values into arguments.
	* Then, The vector will be returned that elements will get same value.
*/
t_vec4	*create_4d_vec_input_3d(t_vec3 *v1, double f);
t_vec4	*create_4d_vec_input_4fs(double f1, double f2, double f3, double f4);
t_vec4	*create_4d_vec_input_same_value(double f);

#endif
