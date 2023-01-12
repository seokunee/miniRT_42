/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:23:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 16:15:06 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_malloc(size_t size)
{
	void *p;

	p = ft_calloc(1, size);
	if (!p)
		exit(1);
	return p;
}
