/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:43:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/15 15:44:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt_math.h"

float	max_float(float f1, float f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

float	min_float(float f1, float f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}
