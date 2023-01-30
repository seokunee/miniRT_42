/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:08 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/30 12:49:24 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "rt_math.h"

/// @brief 한 픽셀에 대한 색상 정보
/// @param t Transparency 투명도, 0 불투명 ~ 255 투명함
/// @param r Red
/// @param g Green
/// @param b Blue
/// @return
static int	create_trgb(unsigned char t, unsigned char r, unsigned char g, \
unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

/// @brief 색깔 벡터에서 mlx에 적용할 int값을 반환한다.
/// @param vec RGB를 갖는 벡터
/// @return
int	get_color(t_vec3 vec)
{
	t_vec3	color;

	color = clamp_3d(vec, 0.0, 255.0);
	return (create_trgb(0, color.x, color.y, color.z));
}

// int	get_color(t_vec4 vec)
// {
// 	t_vec4	color;

// 	color = clamp_4d(vec, 0.0, 255.0);
// 	return (create_trgb(color.x4, color.x1, color.x2, color.x3));
// }

int	white(void)
{
	return (create_trgb(0, 255, 255, 255));
}
