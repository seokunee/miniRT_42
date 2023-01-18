/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:10:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 19:32:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"
#include <stdlib.h>

// t_vec3	norm_3d_vec(t_vec3 v)
// {
// 	t_vec3	*ret;

// 	ret = ft_malloc(sizeof(t_vec3));
// 	ret->x = v->x / v_len(v);
// 	ret->y = v->y / v_len(v);
// 	ret->z = v->z / v_len(v);
// 	return (ret);
// }

t_vec3      vunit(t_vec3 v)
{
    double len = v_len(v);
    if (len == 0)
    {
        // printf("Error\n:Devider is 0");
        exit(0);
    }
    v.x /= len;
    v.y /= len;
    v.z /= len;
    return (v);
}