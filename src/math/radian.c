/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:09:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 20:06:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float	degrees_to_radians_float(float degrees)
{
	const double	pi = 3.1415926535897932385;

	return (degrees * (float)pi / 180.0f);
}

double	degrees_to_radians_double(double degrees)
{
	const double	pi = 3.1415926535897932385;

	return (degrees * pi / 180.0);
}
