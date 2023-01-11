/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/12 08:46:26 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
#define RT_MATH_H

#include "minirt.h"
#include <math.h>

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

/*
* '+', '*', '-' operator of vector
*/
t_vec	*vec_sum(t_vec *v1, t_vec *v2);
t_vec	*vec_multiple(t_vec *v1, t_vec *v2);
t_vec	*vec_subtract(t_vec *v1, t_vec *v2);

/*
* Return a length of vector
*/
float	vec_length(t_vec *v);

/*
* dot and cross product of vector
*/
float	vec_dot(t_vec *v1, t_vec *v2);
t_vec	*vec_cross(t_vec *v1, t_vec *v2);

#endif
