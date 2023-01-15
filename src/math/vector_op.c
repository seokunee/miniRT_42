/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:46:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/15 19:12:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec3	*vec_sum(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v1->x + v2->x;
	ret_vector->y = v1->y + v2->y;
	ret_vector->z = v1->z + v2->z;
	return (ret_vector);
}

t_vec3	*vec_multiple(t_vec3 *v1, float f)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v1->x * f;
	ret_vector->y = v1->y * f;
	ret_vector->z = v1->z * f;
	return (ret_vector);
}

t_vec3	*vec_sub(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v1->x + v2->x;
	ret_vector->y = v1->y + v2->y;
	ret_vector->z = v1->z + v2->z;
	return (ret_vector);
}

t_vec3	*vec_minus(t_vec3 *v)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = -(v->x);
	ret_vector->y = -(v->y);
	ret_vector->z = -(v->z);
	return (ret_vector);
}

float	vec_length(t_vec3 *v)
{
	return (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z));
}
