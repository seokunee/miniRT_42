/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:49:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 17:03:09 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "rt_math.h"

typedef struct s_hit
{
	float	d;		// 광선의 시작부터 충돌 지점까지의 거리
	t_vec3	point;	// 충돌한 위치
	t_vec3	normal;	// 충돌한 위치에서 표면의 수직 벡터
}	t_hit;

void	copy_hit(t_hit *hit_a, t_hit *hit_b);

#endif
