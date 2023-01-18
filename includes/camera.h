/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:52:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/18 12:55:58 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "raytracer.h"
#include "material.h"

/*
class camera {
    public:
        camera() : camera(point3(0,0,-1), point3(0,0,0), vec3(0,1,0), 40, 1, 0, 10) {}

        camera(
            point3 lookfrom,
            point3 lookat,
            vec3   vup,
            double vfov, // vertical field-of-view in degrees
            double aspect_ratio,
            double aperture,
            double focus_dist,
            double _time0 = 0,
            double _time1 = 0
        ) {
            auto theta = degrees_to_radians(vfov);
            auto h = tan(theta/2);
            auto viewport_height = 2.0 * h;
            auto viewport_width = aspect_ratio * viewport_height;

            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup, w));
            v = cross(w, u);

            origin = lookfrom;
            horizontal = focus_dist * viewport_width * u;
            vertical = focus_dist * viewport_height * v;
            lower_left_corner = origin - horizontal/2 - vertical/2 - focus_dist*w;

            lens_radius = aperture / 2;
            time0 = _time0;
            time1 = _time1;
        }

        ray get_ray(double s, double t) const {
            vec3 rd = lens_radius * random_in_unit_disk();
            vec3 offset = u * rd.x() + v * rd.y();
            return ray(
                origin + offset,
                lower_left_corner + s*horizontal + t*vertical - origin - offset,
                random_double(time0, time1)
            );
        }

    private:
        point3 origin;
        point3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
        vec3 u, v, w;
        double lens_radius;
        double time0, time1;  // shutter open/close times
};
*/

typedef struct s_cam_setting
{
	t_vec3	*lookfrom;
	t_vec3	*lookat;
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
	t_vec3	*origin;				//point
	t_vec3	*lower_left_corner;		//point
	t_vec3	*horizontal;
	t_vec3	*vertical;
	t_vec3	*u;
	t_vec3	*v;
	t_vec3	*w;
	double	lens_radius;
	double	time0;		// shutter open
	double	time1;		// shutter close
}	t_cam;

t_cam_setting	cam_setting(t_oneweek *one);
t_cam	create_cam_default(t_oneweek *one);

#endif