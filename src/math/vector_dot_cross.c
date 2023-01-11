/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot_cross.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:14:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 16:14:32 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

float	vec_dot(t_vec *v1, t_vec *v2)
{
	return (float)(v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec	*vec_cross(t_vec *v1, t_vec *v2)
{
	t_vec	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec));
	ret_vector->x = v1->y * v2->z - v1->z * v2->y;
	ret_vector->y = v1->z * v2->x - v1->x * v2->z;
	ret_vector->z = v1->x * v2->y - v1->y * v2->x;
	return ret_vector;
}
