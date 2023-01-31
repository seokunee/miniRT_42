/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/31 11:30:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	terminal_prompt()
{
	ft_printf("Hello, miniRT!\n");
	ft_printf("PRESS KEY what you want to doing something on your keyboard.\n");
	ft_printf("╔═══════════════════════════════════════════╗\n");
	ft_printf("║          miniRT remote controler          ║\n");
	ft_printf("╠═══════╦═══════════════════════════════════╣\n");
	ft_printf("║ PRESS ║              CONTROL              ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   1   ║              CAMERA               ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   2   ║               LIGHT               ║\n");
	ft_printf("╚═══════╩═══════════════════════════════════╝\n");
}

void	remote_controler(char *input)
{
	ft_printf("╔═══════════════════════════════════════════╗\n");
	ft_printf("║          %s remote controler          ║\n", input);
	ft_printf("╠═══════╦═══════════════════════════════════╣\n");
	ft_printf("║ PRESS ║              CONTROL              ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   Q   ║            DOWN X AXIS            ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   W   ║             UP X AXIS             ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   A   ║            DOWN Y AXIS            ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   S   ║             UP Y AXIS             ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   Z   ║            DOWN Z AXIS            ║\n");
	ft_printf("╠═══════╬═══════════════════════════════════╣\n");
	ft_printf("║   X   ║             UP Z AXIS             ║\n");
	ft_printf("╚═══════╩═══════════════════════════════════╝\n");
}
