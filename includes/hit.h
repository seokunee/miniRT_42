/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:49:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 10:51:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
#define HIT_H

#include "rt_math.h"
#include "material.h"

typedef struct s_hit
{
	t_point3	p;
	t_vector	normal;
	t_material	mat;
	double		t;
	int			front_face;
}	t_hit;


#endif
