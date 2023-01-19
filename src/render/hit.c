/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:48:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/19 12:54:48 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"
#include "ray.h"
#include "hit.h"
#include "raytracer.h"

void	set_face_normal(t_hit *hit, t_ray ray, t_vec3 outward_normal)
{
	hit->front_face = v_dot(ray.dir, outward_normal);
	if (hit->front_face < 0)
		hit->front_face = TRUE;
	else
		hit->front_face = FALSE;
	if (hit->front_face)
		hit->normal = vec3(outward_normal.x, outward_normal.y, outward_normal.z);
	else
		hit->normal = vec3(-(outward_normal.x), -(outward_normal.y), -(outward_normal.z));
}

void	*set_hit_lst(t_oneweek *oneweek)
{

	oneweek->hit_lst = ft_malloc(sizeof(t_list));
	while (oneweek->info->t_objs)		// 여기서 objs 돌리면서 hit_lst를 채워야할듯
	{
		
	}
}


/*

class hittable_list : public hittable  {
    public:
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }
        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;

    public:
        std::vector<shared_ptr<hittable>> objects;
};


bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    auto hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}
*/