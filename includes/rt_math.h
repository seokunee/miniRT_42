/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 14:13:49 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
#define RT_MATH_H

// #include "minirt.h"
#include "../src/libft/include/libft.h"
#include <math.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

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
* Return absolute value of float f.
*/
float	abs_float(float f);

/*
* '+', '*', '-' operator of 2D-vector
*/
t_vec2	*v_sum_2d(t_vec2 *v1, t_vec2 *v2);
t_vec2	*v_sub_2d(t_vec2 *v1, t_vec2 *v2);
t_vec2	*v_mul_2d(t_vec2 *v, float f);

/*
* '+', '*', '-' operator of 3D-vector
*/
t_vec3	*v_sum(t_vec3 *v1, t_vec3 *v2);
t_vec3	*v_sub(t_vec3 *v1, t_vec3 *v2);
t_vec3	*v_mul(t_vec3 *v, float f);

/*
* Convert each element to minus element.
*/
t_vec2	*v_minus_2d(t_vec2 *v);
t_vec3	*v_minus(t_vec3 *v);

/*
* Return a length of vector
*/
float	v_len(t_vec3 *v);

/*
* dot and cross product of vector
*/
float	v_dot(t_vec3 *v1, t_vec3 *v2);
t_vec3	*v_cross(t_vec3 *v1, t_vec3 *v2);

/* Create 2D-vector functions
* 1. Input 2 float values into arguments.
* 2. Input a float value into arguments.
	* Then, The vector will be returned that elements will get same value.
*/
t_vec2	*create_2d_vec(float f1, float f2);
t_vec2	*create_2d_vec_input_same_value(float f);

/*
* Create 3D-vector functions
* 1. Input 3 float values into arguments.
* 2. Input a float value into arguments.
	* Then, The vector will be returned that elements will get same value.
* 3. Input a 2D-vector and a float value into arguments.
*/
t_vec3	*create_3d_vec(float f1, float f2, float f3);
t_vec3	*create_3d_vec_input_same_value(float f);
t_vec3	*create_3d_vec_input_2d_vector(t_vec2 *v, float f);

/*
* Create 4D-vector functions.
* 1. Input 2D-vector and 2 float values into arguments.
* 2. Input 3D-vector and a float value into arguments.
* 3. Input 4 float values into arguments.
* 4. Input a float value into arguments.
	* Then, The vector will be returned that elements will get same value.
*/
t_vec4	*create_4d_vec_input_2d_vector(t_vec2 *v, float f1, float f2);
t_vec4	*create_4d_vec_input_3d_vector(t_vec3 *v1, float f);
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

/*
* compare_value.c
* Implement funcions that are comparing 2 float values.
* Return a float value that is suitable for the condition of the function.
*/
float	max_float(float f1, float f2);
float	min_float(float f1, float f2);

/*
* clamp.c
* Constrain a value to lie between two further values.
* clamp returns the vector of v constrained to the range min_val to max_val.
	* The returned vector is computed as min(max(v->element, minVal), maxVal).
*/
t_vec2	*clamp_2d(t_vec2 *v, float min_val, float max_val);
t_vec3	*clamp_3d(t_vec3 *v, float min_val, float max_val);
t_vec4	*clamp_4d(t_vec4 *v, float min_val, float max_val);

#endif
