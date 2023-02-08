/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:05 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/07 13:28:59 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "rt_math.h"
#include "window.h"
#include "raytracer.h"

static t_vec3	transform_screen_to_world(t_info *info, t_vec2 screen)
{
	const double	x_scale = screen.x - (info->win.width / 2);
	const double	y_scale = -(screen.y) + (info->win.height / 2);

	return (vec3(x_scale, y_scale, info->cam.length));
}

void	get_closest_hit_obj(t_list *objs, t_ray ray, t_hit *closest_hit, \
t_obj *closest_obj)
{
	t_hit	hit;
	t_obj	*obj;
	double	closest;

	closest = 100000;
	closest_hit->d = -1;
	while (objs)
	{
		obj = (t_obj *)objs->content;
		if (obj->type == CY)
			hit = check_ray_collision_cylinder(ray, obj);
		else if (obj->type == SP)
			hit = check_ray_collision_sphere(ray, obj);
		else if (obj->type == PL)
			hit = check_ray_collision_plane(ray, obj);
		else if (obj->type == CN)
			hit = check_ray_collision_cone(ray, obj);
		if (hit.d >= 0 && closest > hit.d)
		{
			*closest_hit = hit;
			*closest_obj = *obj;
			closest = hit.d;
		}
		objs = objs->next;
	}
}

static t_vec3	trace_ray(t_info *info, t_ray ray)
{
	t_hit		closest_hit;
	t_obj		closest_obj;
	t_color3	ambient_color;
	t_color3	light_color;
	t_l			*lights;

	lights = NULL;
	get_closest_hit_obj(info->objs, ray, &closest_hit, &closest_obj);
	if (closest_hit.d >= 0.0)
	{
		light_color = black_v3();
		lights = info->lights;
		while (lights)
		{
			light_color = v_sum(light_color, point_light_get(info, \
			lights, closest_hit, closest_obj));
			lights = lights->next;
		}
		ambient_color = v_divide(v_mul_double(info->amb.colors, \
		info->amb.amb_light_ratio), 255.0);
		ambient_color = v_mul(ambient_color, closest_obj.colors);
		return (vmin(v_sum(light_color, ambient_color), white_v3()));
	}
	return (black_v3());
}

int	calculate_pixel_color(t_info *info, int x, int y)
{
	t_vec3	pixel_pos_world;
	t_vec3	ray_dir;

	pixel_pos_world = transform_screen_to_world(info, vec2(x, y));
	ray_dir = norm_3d_vec(v_minus(pixel_pos_world, info->cam.coor));
	info->ray = get_ray(info->cam.coor, ray_dir);
	return (get_color(trace_ray(info, info->ray)));
}
