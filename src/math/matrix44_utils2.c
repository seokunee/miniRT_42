/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix44_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/24 15:28:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

/*
** t_mat44 *mscale(t_vec3 scale)
** {
** 	t_mat44	*mtx;
**
** 	mtx = munit();
** 	mtx->x[0][0] = scale.x;
** 	mtx->x[1][1] = scale.y;
** 	mtx->x[2][2] = scale.z;
** 	return (mtx);
** }
*/

t_vec3			mmult_v(t_vec3 vec, double h, t_mat44 *mtx)
{
	t_vec3	new;

	if (mtx == NULL)
		return (vec);
	new.x = vec.x * mtx->x[0][0]
			+ vec.y * mtx->x[1][0]
			+ vec.z * mtx->x[2][0]
			+ h * mtx->x[3][0];
	new.y = vec.x * mtx->x[0][1]
			+ vec.y * mtx->x[1][1]
			+ vec.z * mtx->x[2][1]
			+ h * mtx->x[3][1];
	new.z = vec.x * mtx->x[0][2]
			+ vec.y * mtx->x[1][2]
			+ vec.z * mtx->x[2][2]
			+ h * mtx->x[3][2];
	return (new);
}

/*
** matrix44 * matrix44
*/

void			mmult_m(t_mat44 *dst, t_mat44 *src)
{
	t_mat44	new;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			new.x[i][j] = 0;
			while (++k < 4)
				new.x[i][j] += dst->x[i][k] * src->x[k][j];
		}
	}
	*dst = new;
}
