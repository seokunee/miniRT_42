/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:24:00 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/20 16:32:51 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
