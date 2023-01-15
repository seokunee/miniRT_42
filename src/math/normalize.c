/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:10:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/15 23:55:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

t_vec3	*normalize_3d_vector(t_vec3 *v)
{
	t_vec3	*ret;

	ret = ft_malloc(sizeof(t_vec3));
	ret->x = v->x / vec_len(v);
	ret->y = v->y / vec_len(v);
	ret->z = v->z / vec_len(v);
	return (ret);
}
