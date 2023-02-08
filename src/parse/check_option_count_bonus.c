/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option_count_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:36:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/01 12:08:07 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_option_count_bonus(char *s, t_num_ele *check_count)
{
	if (ft_strncmp(s, "A", 2) == 0)
		check_count->a_count++;
	else if (ft_strncmp(s, "C", 2) == 0)
		check_count->c_count++;
	else if (ft_strncmp(s, "L", 2) == 0)
		check_count->l_count++;
	else if (ft_strncmp(s, "cy", 2) == 0)
		check_count->objs_count++;
	else if (ft_strncmp(s, "pl", 2) == 0)
		check_count->objs_count++;
	else if (ft_strncmp(s, "sp", 2) == 0)
		check_count->objs_count++;
	if (check_count->a_count > 1 || check_count->c_count > 1)
		error_exit("Invalid number of options");
}
