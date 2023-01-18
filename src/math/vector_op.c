/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:46:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 16:44:43 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec3	*v_sum(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v1->x + v2->x;
	ret_vector->y = v1->y + v2->y;
	ret_vector->z = v1->z + v2->z;
	return (ret_vector);
}

t_vec3	*v_float_mul(t_vec3 *v, float f)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v->x * f;
	ret_vector->y = v->y * f;
	ret_vector->z = v->z * f;
	return (ret_vector);
}

t_vec3	*v_sub(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v1->x - v2->x;
	ret_vector->y = v1->y - v2->y;
	ret_vector->z = v1->z - v2->z;
	return (ret_vector);
}

t_vec3	*v_minus(t_vec3 *v)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = -(v->x);
	ret_vector->y = -(v->y);
	ret_vector->z = -(v->z);
	return (ret_vector);
}

float	v_len(t_vec3 *v)
{
	return (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z));
}
