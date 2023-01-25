/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:43:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 16:29:27 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

double	max_double(double f1, double f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

double	min_double(double f1, double f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}
