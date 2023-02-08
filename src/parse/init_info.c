/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:48:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/01 12:07:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void	init_info(t_info *info)
{
	info->lights = 0;
	info->objs = 0;
	info->num_ele.a_count = 0;
	info->num_ele.c_count = 0;
	info->num_ele.l_count = 0;
	info->num_ele.objs_count = 0;
}
