/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/12 09:12:17 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
#define RT_MATH_H

#include "minirt.h"
#include <math.h>

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec4
{
	float	x1;
	float	x2;
	float	x3;
	float	x4;
}	t_vec4;

/*
* '+', '*', '-' operator of vector
*/
t_vec3	*vec_sum(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vec_multiple(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vec_subtract(t_vec3 *v1, t_vec3 *v2);

/*
* Return a length of vector
*/
float	vec_length(t_vec3 *v);

/*
* dot and cross product of vector
*/
float	vec_dot(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vec_cross(t_vec3 *v1, t_vec3 *v2);

/*
* Create 3D-vector functions
* Input 3 float values into arguments.
*/

/*
* Create 4D-vector functions.
* 1. Input 3D-vector and a float value into arguments.
* 2. Input 4 float values into arguments.
*/
t_vec4	*create_4d_vec_input_3d(t_vec3 *v1, float f);
t_vec4	*create_4d_vec_input_4fs(float f1, float f2, float f3, float f4);

#endif
