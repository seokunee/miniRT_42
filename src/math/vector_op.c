/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:46:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 13:19:17 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3 vec;
	
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point3	point3(double x, double y, double z)
{
	t_point3 point;
	
	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point3	color3(double r, double g, double b)
{
	t_color3	color3;
	
	color3.x = r;
	color3.y = g;
	color3.z = b;
	return (color3);
}

void	vset(t_vec3 *v, double x, double y, double z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

t_vec3	vplus(t_vec3 v1, t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3	vplus_double(t_vec3 v, double x, double y, double z)
{
	v.x += x;
	v.y += y;
	v.z += z;
	return (v);
}

t_vec3	v_minus(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3	v_minus_double(t_vec3 v, double x, double y, double z)
{
	v.x -= x;
	v.y -= y;
	v.z -= z;
	return (v);
}

t_vec3	v_mul(t_vec3 v1, t_vec3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vec3	v_mul_double(t_vec3 v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

t_vec3	v_divide(t_vec3 v, double t)
{
	v.x *= 1 / t;
	v.y *= 1 / t;
	v.y *= 1 / t;
	return (v);
}

double	v_len(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
