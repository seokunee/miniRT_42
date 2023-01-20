/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 14:29:44 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "info.h"
#include "parse.h"
#include "raytracer.h"
#include "window.h"
#include "thread.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		error_exit("Invalid number of arguments. Check it!");
	parse_rt_file(&info, av[1]);
	init_window(&info.win);
	binding_events(&info.win);
	start_drawing(&info); // 얘가 그리는 거
	mlx_loop(info.win.mlx);
	// print_all_info(&info); // info 내용 프린트
	// while 
	// int	color = calculate_pixel_color(&info, 300, 300);
	// system("leaks miniRT");
	return (0);
}
