/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:07 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 13:23:43 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "raytracer.h"
#include "info.h"
#include "rt_math.h"
#include "memory.h"
#include "parse.h"
#include "window.h"

# define TRUE	1
# define FALSE	0

/*
* error/error.c
*/
void	error_exit(char *msg);

#endif
