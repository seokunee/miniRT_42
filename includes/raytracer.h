/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:39:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 11:48:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
#define RAYTRACER_H

// #include "minirt.h"
#include "camera.h"
#include "info.h"
#include "material.h"

typedef struct s_oneweek
{
	struct s_info	*info;
	struct s_image	*image;
	struct s_cam	cam;
	struct s_list	*hit_lst;
}	t_oneweek;


#endif
