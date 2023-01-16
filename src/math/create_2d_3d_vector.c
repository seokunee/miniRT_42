/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2d_3d_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:18:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/15 15:53:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec2	*create_2d_vec(float f1, float f2)
{
	t_vec2	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec2));
	ret_vector->x = f1;
	ret_vector->y = f2;
	return (ret_vector);
}

t_vec2	*create_2d_vec_input_same_value(float f)
{
	t_vec2	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec2));
	ret_vector->x = f;
	ret_vector->y = f;
	return (ret_vector);
}

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

t_vec3	*create_3d_vec_input_2d_vector(t_vec2 *v, float f)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v->x;
	ret_vector->y = v->y;
	ret_vector->z = f;
	return (ret_vector);
}
