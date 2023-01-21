/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/21 23:33:13 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "error.h"
#include "parse.h"
#include "thread.h"


#include "raytracer.h"
void	test_drawing(t_info *info)
{
	int			x;
	int			y;
	int			color;

	x = 0;
	while (x < 100)
	{
		y = 0;
		printf("x: %d, color: ", x);
		while (y < 100)
		{
			color = calculate_pixel_color(info, x, y);
			// put_pixel(&drawer->data, x, y, color);
			printf("%d ", color);
			(void)color;
			y++;
		}
		x++;
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		error_exit("Invalid number of arguments. Check it!");
	parse_rt_file(&info, av[1]);
	info.wid = 100;
	info.hei = 100;
	print_all_info(&info); // info 내용 프린트
	test_drawing(&info);
	// init_window(&info.win);
	// binding_events(&info.win);
	// start_drawing(&info);
	// mlx_loop(info.win.mlx);
	// while
	// int	color = calculate_pixel_color(&info, 300, 300);
	// system("leaks miniRT");
	return (0);
}
