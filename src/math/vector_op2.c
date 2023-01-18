/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:28:29 by yje               #+#    #+#             */
/*   Updated: 2023/01/16 16:44:15 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec3	*v_mul(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*ret_vector;

	ret_vector = ft_malloc(sizeof(t_vec3));
	ret_vector->x = v1->x * v2->x;
	ret_vector->y = v1->y * v2->y;
	ret_vector->z = v1->z * v2->z;
	return (ret_vector);
}


