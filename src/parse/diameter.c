/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diameter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:50:22 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/19 09:43:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "info.h"

void	check_diameter(t_objs *obj, float dia)
{
	if (dia <= 0)
		error_exit("Wrong diameter range");
	obj->diameter = dia;
}
