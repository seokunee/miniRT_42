/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwo <chanwo@student.42seoul.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:52:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/25 14:06:19 by chanwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "libft.h"

typedef struct s_vec2	t_vec2;
typedef struct s_vec2	t_point2;
typedef struct s_vec2	t_color2;

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

typedef struct s_vec4	t_vec4;
typedef struct s_vec4	t_point4;
typedef struct s_vec4	t_color4;

struct s_vec2
{
	double	x;
	double	y;
};

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_vec4
{
	double	x1;
	double	x2;
	double	x3;
	double	x4;
};

typedef struct s_ray
{
	t_vec3	orig;	//point
	t_vec3	normal;
	double	tm;
}	t_ray;

typedef struct s_cam_setting
{
	t_vec3	lookfrom;
	t_vec3	lookat;
	t_vec3	vup;
	double	vfov;
	double	aspect_ratio;
	double	aperture;
	double	focus_dist;
	double	time0;
	double	time1;
}	t_cam_setting;

typedef struct s_cam
{
	t_vec3	origin;				//point
	t_vec3	lower_left_corner;		//point
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	double	lens_radius;
	double	time0;		// shutter open
	double	time1;		// shutter close
}	t_cam;

typedef struct s_hit
{
	double	d;
	t_vec3	point;
	t_vec3	normal;
	// std::shared_ptr<Object> obj; // 나중에 물체의 재질 등을 가져오기 위한 포인터
}	t_hit;

/*
* Ambient lightning:
* identifier: A
* ambient lighting ratio in range [0.0,1.0]: 0.2
* R,G,B colors in range [0-255]: 255, 255, 255
*/
typedef struct s_a
{
	double			amb_light_ratio;
	struct s_vec3	colors;
}	t_a;

/*
* Camera:
* identifier: C
* x,y,z coordinates of the view point: 0.0,0.0,20.6
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* FOV : Horizontal field of view in degrees in range [0,180]
* length : Distance from camera to monitor
*/
typedef struct s_c
{
	struct s_vec3	coor;
	struct s_vec3	normal;
	int				fov;
	double			length;
}	t_c;

/*
* Light:
* identifier: L
* x,y,z coordinates of the light point: 0.0,0.0,20.6
* the light brightness ratio in range [0.0,1.0]: 0.6
* (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/
typedef struct s_l
{
	t_vec3		coor;
	double		light_brightness_ratio;
	/* unsued in mand part */
	t_vec3		colors;
	struct s_l	*next;
	struct s_l	*prev;
}	t_l;

/*
* PL : Plane
* SP : Sphere
* CY : Cylinder
*/
typedef enum e_type
{
	NO_OBJS,
	PL,
	SP,
	CY,
}	t_type;

/*
* Objs:
* identifier : objs type
* x,y,z coordinates: 50.0,0.0,20.6
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* the cylinder diameter: 14.2
* the cylinder height: 21.42
* R,G,B colors in range [0,255]: 10, 0, 255
*/
typedef struct s_obj
{
	enum e_type		type;
	t_vec3			coor;
	t_vec3			normal;
	double			diameter;
	double			cy_hei;
	t_vec3			colors;
	struct s_obj	*next;
	struct s_obj	*prev;
	// test
	t_vec3 			amb;
	t_vec3			diff;
	t_vec3			spec;
	float			ks;
	float			alpha; // 투명도
}	t_obj;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}	t_window;

/*
* info
*/
typedef struct s_info
{
	t_a			amb;
	t_c			cam;
	t_l			*lights;
	t_list		*objs;
	t_window	win;

	// tmp
	t_hit		*hit;
	t_vec3		color;
	t_vec3		phong_color;
	double		diff;
	double		specular;
}	t_info;

/*
* check_flag
* explaination : check number of flags in '.rt file'
*/
typedef struct s_check_flag
{
	int	a_count;
	int	c_count;
	int	l_count;
	int	pl_count;
	int	sp_count;
	int	cy_count;
}	t_check_flag;

typedef struct s_drawer
{
	int			i;
	int			width;
	int			height;
	int			size;
	pthread_t	thread;
	t_data		data;
	t_info		*info;
}	t_drawer;

typedef struct s_color
{
	int	tmp;
}	t_color;

typedef struct s_perlin
{
	int	tmp;
}	t_perlin;

typedef struct s_texture
{
	char			*type;
	t_color			color_value;
	t_color			even;
	t_color			odd;
	t_perlin		noise;
	double			scale;
	unsigned char	*data;
	int				wid;
	int				hei;
	int				byte_per_scanline;
}	t_texture;

typedef struct s_image
{
	double	aspect;
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
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	bool		front_face;
	t_color3	color;
}	t_hit_record;

#endif
