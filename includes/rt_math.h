/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/13 23:21:48 by chanwjeo         ###   ########.fr       */
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
* 1. Input 3 float values into arguments.
* 2. Input a float values into arguments.
	* Then, The vector will be returned that elements will get same value.
*/
t_vec3	*create_3d_vec(float f1, float f2, float f3);
t_vec3	*create_3d_vec_input_same_value(float f);

/*
* Create 4D-vector functions.
* 1. Input 3D-vector and a float value into arguments.
* 2. Input 4 float values into arguments.
* 3. Input a float values into arguments.
	* Then, The vector will be returned that elements will get same value.
*/
t_vec4	*create_4d_vec_input_3d(t_vec3 *v1, float f);
t_vec4	*create_4d_vec_input_4fs(float f1, float f2, float f3, float f4);
t_vec4	*create_4d_vec_input_same_value(float f);

/*
* Return normalized 3D-vector.
*/
t_vec3	*normalize_3d_vector(t_vec3 *v);

/*
* Calculate power of float value.
* Input 2 float numbers, base and exp.
*/
float	float_pow(float base, float exp);


#endif
