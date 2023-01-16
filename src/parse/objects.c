/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:52:00 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 01:56:42 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	check_obj(t_objs *obj, char **opt, t_type type)
{
	obj->type = type;
	if (type == PL)
		set_pl(obj, opt);
	if (type == SP)
		set_sp(obj, opt);
	if (type == CY)
		set_cy(obj, opt);
}

void	get_obj(t_info *info, char **opt, t_type type)
{
	t_objs *obj;
	t_list *new;

	obj = malloc(sizeof(t_objs));
	if (!obj)
		error_exit("malloc error");
	new = ft_lstnew(obj);
	ft_lstadd_back(&(info->t_objs), new);
	check_obj(obj, opt, type);
}
