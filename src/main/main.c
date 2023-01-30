/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/30 19:06:29 by yje              ###   ########.fr       */
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
	parse_rt_file(&info, av[1]);
	init_window(&info.win);
	camera_setting(&info);
	rotate(&rotate_info, &info);
	printf_before_after(&info, &rotate_info);
	binding_events(&rotate_info.win);
	start_drawing(&rotate_info);
	system("leaks miniRT");
	mlx_loop(rotate_info.win.mlx);
	return (0);
}
