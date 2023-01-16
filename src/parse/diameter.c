/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diameter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:50:22 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 01:50:28 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	check_diameter(t_objs *obj, float dia)
{
	if (dia <= 0)
		error_exit("wrong argument");
	obj->diameter = dia;
}
