/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:00:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/12 09:24:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec3	*create_3d_vec(float f1, float f2, float f3)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = f1;
	ret_vector->y = f2;
	ret_vector->z = f3;
	return (ret_vector);
}

t_vec3	*create_3d_vec_input_same_value(float f)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = f;
	ret_vector->y = f;
	ret_vector->z = f;
	return (ret_vector);	
}

t_vec4	*create_4d_vec_input_3d(t_vec3 *v1, float f)
{
	t_vec4	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec4));
	ret_vector->x1 = v1->x;
	ret_vector->x2 = v1->y;
	ret_vector->x3 = v1->z;
	ret_vector->x4 = f;
	return (ret_vector);
}

t_vec4	*create_4d_vec_input_4fs(float f1, float f2, float f3, float f4)
{
	t_vec4	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec4));
	ret_vector->x1 = f1;
	ret_vector->x2 = f2;
	ret_vector->x3 = f3;
	ret_vector->x4 = f4;
	return (ret_vector);
}

t_vec4	*create_4d_vec_input_same_value(float f)
{
	t_vec4	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec4));
	ret_vector->x1 = f;
	ret_vector->x2 = f;
	ret_vector->x3 = f;
	ret_vector->x4 = f;
	return (ret_vector);	
}
