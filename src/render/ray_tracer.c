/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:10:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 22:16:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_hit	*find_closest_collision(t_info *info, t_ray *ray)
{
	float	closest_d;
	t_hit	*closest_hit;
	t_hit	*tmp_hit;
	t_list	*tmp_list;

	closest_hit = NULL;
	closest_d = 2147483647.0f;
	tmp_list = info->objs;
	while (tmp_list != NULL)
	{
		tmp_hit = check_ray_collision(ray);
		if (tmp_hit->d >= 0.0f && tmp_hit->d < closest_d)
		{
			if (closest_hit)
				free(closest_hit);
			closest_hit = tmp_hit;
		}
		// t_list = t_list->next;
	}
}

t_vec3	*transform_screen_to_world(t_info *info, t_vec2 *screen)
{
	t_vec3	*world;

	world = ft_malloc(sizeof(t_vec3));
	world->x = (screen->x * 2.0f / (float)info->width - 1.0f) * \
		(float)(info->width) / (float)(info->height);
	world->y = (-(screen->y) * 2.0f / (float)info->height + 1.0f);
	world->z = 0.0f;
	return (world);
}

// 임시로 정의해놓음
t_vec3	*trace_ray(t_info *info, t_ray *ray, const int recurse_level)
{
	t_vec3	*dir_to_light;
	t_vec3	*reflect_dir;

	if (recurse_level < 0)
		return (create_3d_vec_input_same_value(0.0f));
	info->hit = find_closest_collision(info, ray);
	if (info->hit->d >= 0.0f)
	{
		if (info->color)
			free(info->color);
		if (info->phong_color)
			free(info->phong_color);
		info->color = create_3d_vec_input_same_value(0.0f);
		info->phong_color = create_3d_vec_input_same_value(0.0f);
		dir_to_light = normalize_3d_vector(v_sub(info->t_l->coor, info->hit->point));
		info->diff = max_float(v_dot(info->hit->normal, dir_to_light), 0.0f);
		reflect_dir = v_sub(v_mul(v_mul(info->hit->normal, 2.0f), v_dot(dir_to_light, info->hit->normal)), dir_to_light);
		info->specular = powf(max_float(v_dot(v_minus(ray->dir), reflect_dir), 0.0f), info->hit->obj->alpha);

		// 함수 내부에서 free를 해주면 깔끔할듯
		if (hit->obj->amb_texture)
			rt->phong_color = v_sum(rt->phong_color, v_cross(hit->obj->amb, sample_linear(hit->uv)));
		else
			rt->phong_color = v_sum(rt->phong_color, hit->obj->amb);
		if (hit->obj->dif_texture)
			rt->phong_color = v_sum(rt->phong_color, (v_mul(hit->obj->dif, diff)))
		
	}
}

// 광선이 물체에 닿으면 그 물체의 색 반환
vec3 traceRay(Ray &ray, const int recurseLevel)
{
	if (recurseLevel < 0)
		return vec3(0.0f);

	// Render first hit
	const auto hit = FindClosestCollision(ray);

	if (hit.d >= 0.0f)
	{
		glm::vec3 color(0.0f);

		// Diffuse
		const vec3 dirToLight = glm::normalize(light.pos - hit.point);

		glm::vec3 phongColor(0.0f);

		const float diff = glm::max(dot(hit.normal, dirToLight), 0.0f);

		// Specular
		const vec3 reflectDir = hit.normal * 2.0f * dot(dirToLight, hit.normal) - dirToLight;
		const float specular = glm::pow(glm::max(glm::dot(-ray.dir, reflectDir), 0.0f), hit.obj->alpha);

		if (hit.obj->ambTexture)
		{
			phongColor += hit.obj->amb * hit.obj->ambTexture->SampleLinear(hit.uv);
		}
		else
		{
			phongColor += hit.obj->amb;
		}

		if (hit.obj->difTexture)
		{
			phongColor += diff * hit.obj->dif * hit.obj->difTexture->SampleLinear(hit.uv);
		}
		else
		{
			phongColor += diff * hit.obj->dif;
		}

		phongColor += hit.obj->spec * specular;

		color += phongColor * (1.0f - hit.obj->reflection - hit.obj->transparency);

		if (hit.obj->reflection)
		{
			const auto reflectedDirection = glm::normalize(2.0f * hit.normal * dot(-ray.dir, hit.normal) + ray.dir);
			Ray reflection_ray{hit.point + reflectedDirection * 1e-4f, reflectedDirection}; // add a small vector to avoid numerical issue

			color += traceRay(reflection_ray, recurseLevel - 1) * hit.obj->reflection;
		}

		// 참고
		// https://samdriver.xyz/article/refraction-sphere (그림들이 좋아요)
		// https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/reflection-refraction-fresnel (오류있음)
		// https://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/reflection_refraction.pdf (슬라이드가 보기 좋지는 않지만 정확해요)
		if (hit.obj->transparency)
		{
			const float ior = 1.5f; // Index of refraction (유리: 1.5, 물: 1.3)

			float eta; // sinTheta1 / sinTheta2
			vec3 normal;

			if (glm::dot(ray.dir, hit.normal) < 0.0f) // 밖에서 안에서 들어가는 경우 (예: 공기->유리)
			{
				eta = ior;
				normal = hit.normal;
			}
			else // 안에서 밖으로 나가는 경우 (예: 유리->공기)
			{
				eta = 1.0f / ior;
				normal = -hit.normal;
			}

			// const float cosTheta1 = ... ;
			// const float sinTheta1 = ... ; // cos^2 + sin^2 = 1
			// const float sinTheta2 = ... ;
			// const float cosTheta2 = ... ;

			// const vec3 m = glm::normalize(...);
			// const vec3 a = ...;
			// const vec3 b = ...;
			// const vec3 refractedDirection = glm::normalize(a + b); // transmission

			// color += ...;

			// Fresnel 효과는 생략되었습니다.
		}

		return color;
	}

	return vec3(0.0f);
}
