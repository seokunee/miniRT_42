/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/01 21:23:16 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "error.h"
#include "parse.h"
#include "window.h"
#include "thread.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_info	rotate_info;

	if (ac != 2)
		error_exit("Invalid number of arguments. Check it!");
	init_window(&info.win);
	parse_rt_file(&info, av[1]);
	camera_setting(&info);
	rotate(&rotate_info, &info);
	binding_events(&rotate_info);
	// printf_before_after(&info, &rotate_info);
	// system("leaks miniRT");
	mlx_loop(rotate_info.win.mlx);
	return (0);
}
