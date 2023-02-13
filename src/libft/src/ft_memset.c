/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:31:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/16 20:20:21 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;

	b_char = (unsigned char *)b;
	while (len > 0)
	{
		*b_char = (unsigned char)c;
		++b_char;
		--len;
	}
	return (b);
}
