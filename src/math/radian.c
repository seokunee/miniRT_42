/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:09:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/01 21:18:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <rt_math.h>

float	degrees_to_radians_float(float degrees)
{
	return (degrees * (float)PI / 180.0f);
}

double	degrees_to_radians_double(double degrees)
{
	return (degrees * PI / 180.0);
}
