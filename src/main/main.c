/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 16:19:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	error_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		error_exit("Invalid number of arguments. Check it!");
	init_info(&info);
	parse_rt_file(&info, av[1]);
	printf("%s\n", av[1]);
	system("leaks miniRT");
	return (0);
}
