/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:52:28 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/25 19:17:38 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_hit	get_hit(double d, t_vec3 point, t_vec3 normal)
{
	t_hit	hit;

	hit.d = d;
	hit.point = point;
	hit.normal = normal;
	return (hit);
}
