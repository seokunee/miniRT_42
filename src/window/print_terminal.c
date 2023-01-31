/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/31 16:18:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdio.h>

void	terminal_prompt()
{
	printf("Hello, miniRT!\n");
	printf("PRESS KEY what you want to doing something on your keyboard.\n");
	printf("╔═══════════════════════════════════════════╗\n");
	printf("║          miniRT remote controler          ║\n");
	printf("╠═══════╦═══════════════════════════════════╣\n");
	printf("║ PRESS ║              CONTROL              ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   1   ║              CAMERA               ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   2   ║               LIGHT               ║\n");
	printf("╚═══════╩═══════════════════════════════════╝\n");
}

void	remote_controler(char *input)
{
	printf("╔═══════════════════════════════════════════╗\n");
	printf("║          %s remote controler              ║\n", input);
	printf("╠═══════╦═══════════════════════════════════╣\n");
	printf("║ PRESS ║              CONTROL              ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   Q   ║            DOWN X AXIS            ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   W   ║             UP X AXIS             ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   A   ║            DOWN Y AXIS            ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   S   ║             UP Y AXIS             ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   Z   ║            DOWN Z AXIS            ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   X   ║             UP Z AXIS             ║\n");
	printf("╚═══════╩═══════════════════════════════════╝\n");
}

void	light_selector()
{
	printf("╔═══════════════════════════════════════════╗\n");
	printf("║              LIGHT : TURN ON              ║\n");
	printf("╚═══════════════════════════════════════════╝\n");
	printf("╔═══════════════════════════════════════════╗\n");
	printf("║              LIGHT SELECTOR               ║\n");
	printf("╠══════════════╦══════════════╦═════════════╣\n");
	printf("║     BACK     ║     NEXT     ║     OKAY    ║\n");
	printf("╠══════════════╬══════════════╬═════════════╣\n");
	printf("║       B      ║       N      ║      O      ║\n");
	printf("╚══════════════╩══════════════╩═════════════╝\n");
	printf("To exit the light controler, PRESS the 2 key\n");
}
