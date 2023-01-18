/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_2d2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:46:38 by yje               #+#    #+#             */
/*   Updated: 2023/01/16 16:44:29 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec2	*v_mul_2d(t_vec2 *v1, t_vec2 *v2)
{
	t_vec2	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec2));
	ret_vector->x = v1->x * v2->x;
	ret_vector->y = v1->y * v2->y;
	return(ret_vector);
}