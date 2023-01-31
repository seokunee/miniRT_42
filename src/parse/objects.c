/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:52:00 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/25 17:39:37 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "parse.h"

void	check_obj(t_obj *obj, char **opt, t_type type)
{
	obj->type = type;
	if (type == PL)
		set_pl(obj, opt);
	if (type == SP)
		set_sp(obj, opt);
	if (type == CY)
		set_cy(obj, opt);
	if (type == CN)
		set_cn(obj, opt);
}

void	get_obj(t_info *info, char **opt, t_type type)
{
	t_obj	*obj;
	t_list	*new;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		error_exit("malloc error");
	new = ft_lstnew(obj);
	ft_lstadd_back(&(info->objs), new);
	check_obj(obj, opt, type);
}
