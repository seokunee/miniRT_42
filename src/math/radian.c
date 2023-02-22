/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:09:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/20 16:25:09 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <rt_math.h>

double	degrees_to_radians_double(double degrees)
{
	return (degrees * PI / 180.0);
}
