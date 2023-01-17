/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diameter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:50:22 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 18:22:27 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_diameter(t_objs *obj, float dia)
{
	if (dia <= 0)
		error_exit("Wrong diameter range");
	obj->diameter = dia;
}
