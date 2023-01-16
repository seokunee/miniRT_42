/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:07 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 21:14:52 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../src/mlx/mlx.h"
#include "../src/libft/include/libft.h"
#include "raytracer.h"
#include "info.h"
#include "rt_math.h"
#include "memory.h"
#include "parse.h"

# define TRUE	1
# define FALSE	0

/*
* main.c
*/
void	error_exit(char *msg);

#endif
