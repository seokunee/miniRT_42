/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:33:01 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 16:55:17 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "raytracer.h"

typedef struct s_image
{
	float	aspect;
	int		sample_per_pixel;
	int		max_depth;
}	t_image;

typedef struct s_material
{
	char				type[1];
	t_vec3				*color_albedo;
	double				fuzz_ir;
	struct s_material	*next;
}	t_material;

typedef struct s_hit_record
{
	t_vec3		p;	// point
	t_vec3		normal;
	t_material	*mat_ptr;
	double		t;
	int			front_face;	// bool
}	t_hit_record;

#endif
