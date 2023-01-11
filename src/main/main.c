/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 09:56:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		error_exit("Invalid number of arguments. Check it!");
	init_info(&info);
	printf("%s\n", av[1]);
	system("leaks miniRT");
	return (0);
}
