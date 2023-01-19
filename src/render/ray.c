/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:43:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 10:44:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"

t_vec3	create_ray(t_vec3 ori, t_vec3 dir, float t)
{
	t_ray	ray;

	ray.orig = ori;
	ray.dir = dir;
	ray.tm = t;
	return (ray);
}

t_ray	get_ray(t_cam cam, double s, double t)
{
	return (create_ray(cam.origin, v_sub(v_sum(cam.lower_left_corner, \
		v_float_mul(cam.horizontal, s)), cam.origin)), 0);
}

t_vec3	ray_at(t_ray ray, float t)
{
	return (v_sum(ray.orig, v_float_mul(ray.dir, t)));
}

// t_color3	ray_color(t_ray ray, const )

/*
color ray_color(const ray& r, const hittable& world, int depth) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0,0,0);

    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return color(0,0,0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}
*/