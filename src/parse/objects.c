/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:52:00 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/02 14:49:50 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "parse.h"

static void	check_obj(t_info *info, t_obj *obj, char **opt, t_type type)
{
	obj->type = type;
	if (type == PL)
		set_pl(info, obj, opt);
	if (type == SP)
		set_sp(info, obj, opt);
	if (type == CY)
		set_cy(info, obj, opt);
	if (type == CN)
		set_cn(info, obj, opt);
}

void	get_obj(t_info *info, char **opt, t_type type)
{
	t_obj	*obj;
	t_list	*new;

	obj = ft_malloc(sizeof(t_obj));
	new = ft_lstnew(obj);
	ft_lstadd_back(&(info->objs), new);
	check_obj(info, obj, opt, type);
}
