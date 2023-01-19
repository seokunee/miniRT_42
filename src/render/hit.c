/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:48:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 10:59:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"






// struct hit_record {
//     point3 p;
//     vec3 normal;
//     shared_ptr<material> mat_ptr;
//     double t;
//     bool front_face;

//     inline void set_face_normal(const ray& r, const vec3& outward_normal) {
//         front_face = dot(r.direction(), outward_normal) < 0;
//         normal = front_face ? outward_normal :-outward_normal;
//     }
// };


// class hittable {
//     public:
//         virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
// };