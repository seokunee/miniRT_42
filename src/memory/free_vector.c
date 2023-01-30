/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:41:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 16:29:53 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	free_vec_2d(t_vec2 *v)
{
	free(v);
}

void	free_vec_3d(t_vec3 *v)
{
	free(v);
}

void	free_vec_4d(t_vec4 *v)
{
	free(v);
}