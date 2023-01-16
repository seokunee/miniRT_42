/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_raytracer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:43:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 14:19:41 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

// void	free_raytracer(t_raytracer *rt)
// {
// 	if (rt->light)
// 		free(rt->light);
// 	if (rt->object)
// 		ft_lstclear(rt->object, free_);	// 이곳에 content 할당 해제하는 함수 넣어주면 될듯.
// 	free(rt);
// }

void	free_ray(t_ray *ray)
{
	if (ray->start)
		free(ray->start);
	if (ray->dir)
		free(ray->dir);
	free(ray);
}

void	free_hit(t_hit *hit)
{
	if (hit->normal)
		free(hit->normal);
	if (hit->point)
		free(hit->point);
	if (hit->uv)
		free(hit->uv);
	free(hit);
}

void	free_tri(t_tri *tri)
{
	if (tri->uv0)
		free(tri->uv0);
	if (tri->uv1)
		free(tri->uv1);
	if (tri->uv2)
		free(tri->uv2);
	if (tri->v0)
		free(tri->v0);
	if (tri->v1)
		free(tri->v1);
	if (tri->v2)
		free(tri->v2);
	free(tri);
}
