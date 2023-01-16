/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:49:48 by yje               #+#    #+#             */
/*   Updated: 2023/01/16 00:01:23 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec2	*v_sum_2d(t_vec2 *v1, t_vec2 *v2)
{
	t_vec2	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec2));
	ret_vector->x = v1->x + v2->x;
	ret_vector->y = v1->y + v2->y;
	return(ret_vector);
}

t_vec2	*v_sub_2d(t_vec2 *v1, t_vec2 *v2)
{
	t_vec2	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec2));
	ret_vector->x = v1->x - v2->x;
	ret_vector->y = v1->y - v2->y;
	return (ret_vector);
}

t_vec2	*v_mul_2d(t_vec2 *v, float f)
{
	t_vec2	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec2));
	ret_vector->x = v->x * f;
	ret_vector->y = v->y * f;
	return(ret_vector);
}

t_vec2	*v_minus_2d(t_vec2 *v)
{
	t_vec2	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec2));
	ret_vector->x = -(v->x);
	ret_vector->y = -(v->y);
	return (ret_vector);
}
