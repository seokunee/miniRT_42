/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/24 15:35:30 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

// #include "minirt.h"
# include <math.h>

typedef struct s_vec2	t_vec2;
typedef struct s_vec2	t_point2;
typedef struct s_vec2	t_color2;

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

typedef struct s_vec4	t_vec4;
typedef struct s_vec4	t_point4;
typedef struct s_vec4	t_color4;

typedef struct s_mat44	t_mat44;

struct s_vec2
{
	double	x;
	double	y;
};

struct s_vec3
{

	double	x;
	double	y;
	double	z;
};

struct s_vec4
{
	double	x1;
	double	x2;
	double	x3;
	double	x4;
};

struct s_mat44
{
	double	x[4][4];
	t_vec3	rotate_deg;
};

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

t_vec3		v_sum(t_vec3 v1, t_vec3 v2);
t_vec3		v_sum_double(t_vec3 v, double x, double y, double z);
t_vec3		v_change_minus(t_vec3 v1);
t_vec3		v_minus(t_vec3 v1, t_vec3 v2);
t_vec3		v_minus_double(t_vec3 v, double x, double y, double z);
t_vec3		v_mul(t_vec3 v1, t_vec3 v2);
t_vec3		v_mul_double(t_vec3 v, double t);
t_vec3		v_divide(t_vec3 v, double t);
t_vec3		vunit(t_vec3 v);
t_vec3		norm_3d_vec(t_vec3 v);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);

float		min_float(float f1, float f2);
float		max_float(float f1, float f2);

// t_vec2	clamp_2d(t_vec2 v, float min_val, float max_val);
t_vec3		clamp_3d(t_vec3 v, float min_val, float max_val);
// t_vec4	clamp_4d(t_vec4 v, float min_val, float max_val);
// t_vec3	*vec_multiple(t_vec3 *v1, t_vec3 *v2);
// t_vec3	*vec_subtract(t_vec3 *v1, t_vec3 *v2);

/*
* Return a length of vector
*/
double		v_len(t_vec3 v);

/*
* dot and cross product of vector
*/
double		v_dot(t_vec3 v1, t_vec3 v2);
t_vec3		v_cross(t_vec3 v1, t_vec3 v2);

float		degrees_to_radians_float(float degrees);
double		degrees_to_radians_double(double degrees);

/*
* Matrix of 4x4
*/
t_mat44		*munit(void);
t_mat44		*mrotate_x(double degree);
t_mat44		*mrotate_y(double degree);
t_mat44		*mrotate_z(double degree);
t_mat44		*rotate(t_vec3 rotate);
t_vec3		mmult_v(t_vec3 vec, double h, t_mat44 *mtx);
void		mmult_m(t_mat44 *dst, t_mat44 *src);
t_mat44		*inverse(t_mat44 a);
t_mat44		transpose(t_mat44 *orig);
t_mat44		*rotate_normal(t_mat44 *rotate);

#endif
