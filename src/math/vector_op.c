/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:46:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 16:14:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec	*vec_sum(t_vec *v1, t_vec *v2)
{
	t_vec	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec));
	ret_vector->x = v1->x + v2->x;
	ret_vector->y = v1->y + v2->y;
	ret_vector->z = v1->z + v2->z;
	return ret_vector;
}

t_vec	*vec_multiple(t_vec *v1, t_vec *v2)
{
	t_vec	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec));
	ret_vector->x = v1->x * v2->x;
	ret_vector->y = v1->y * v2->y;
	ret_vector->z = v1->z * v2->z;
	return ret_vector;
}

t_vec	*vec_subtract(t_vec *v1, t_vec *v2)
{
	t_vec	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec));
	ret_vector->x = v1->x + v2->x;
	ret_vector->y = v1->y + v2->y;
	ret_vector->z = v1->z + v2->z;
	return ret_vector;
}
