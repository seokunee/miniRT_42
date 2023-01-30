/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:36:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/30 15:17:41 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

void	check_option_count(char *s, t_check_flag *check_count)
{
	if (ft_strncmp(s, "A", 2) == 0)
		check_count->a_count++;
	else if (ft_strncmp(s, "C", 2) == 0)
		check_count->c_count++;
	else if (ft_strncmp(s, "L", 2) == 0)
		check_count->l_count++;
	if (check_count->a_count > 1 || check_count->c_count > 1)
		error_exit("Invalid number of options");
}
