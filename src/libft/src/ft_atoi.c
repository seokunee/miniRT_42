/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:22:31 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/20 17:11:17 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

extern bool	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	size_t			sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		sum *= 10;
		sum += (*str - '0');
		++str;
	}
	if (sign > 0 && sum > LONG_MAX + 0)
		return (-1);
	else if (sign < 0 && sum > (size_t)LONG_MAX + 1)
		return (0);
	return ((int)(sum * sign));
}

int	ft_atoi_stream(char **str)
{
	size_t			sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (**str && ft_isspace(**str))
		++(*str);
	if (**str && (**str == '-' || **str == '+'))
	{
		if (**str == '-')
			sign = -1;
		++(*str);
	}
	while (**str && (**str >= '0' && **str <= '9'))
	{
		sum *= 10;
		sum += (**str - '0');
		++(*str);
	}
	if (sign > 0 && sum > LONG_MAX + 0)
		return (-1);
	else if (sign < 0 && sum > (size_t)LONG_MAX + 1)
		return (0);
	return ((int)(sum * sign));
}
