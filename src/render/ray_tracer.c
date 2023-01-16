/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:10:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 09:31:53 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_hit	*find_closest_collision(t_ray *ray)
{
	float	closest_d;
	t_hit	*closest_hit;
	t_hit	*tmp_hit
	// t_list	*head;	필요하다면 사용

	closest_hit = NULL;
	closest_d = 2147483647.0f
	while (end_of_tlist)
	{
		tmp_hit = check_ray_collision(t_list->content);
		if (tmp_hit->d >= 0.0f && tmp_hit->d < closest_d)
		{
			if (closest_hit)
				free(closest_hit);
			closest_hit = tmp_hit;
		}
		// t_list = t_list->next;
	}
}

