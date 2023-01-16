/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitls2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:54:05 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 01:54:10 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_oper(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (ERR);
		i++;
	}
	return (SUCCESS);
}
