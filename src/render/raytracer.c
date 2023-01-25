/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjeeokcoi <yjeeokcoi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:13:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/25 15:599:46 by yje     eokcoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "structs.h"
#include "rt_math.h"

static int	create_trgb_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
* transform_screen_to_world
* 화면 비율에 맞게 x,y축 길이 조정 + z축 생성
*/
static t_vec3	transform_screen_to_world(t_window *win, t_vec2 screen)
{
	// const double	x_scale = 2.0 / (win->width - 1);
	// const double	y_scale = 2.0 / (win->height - 1);
	// const double	aspect = (double)(win->width) / (double)(win->height);

	// return (vec3((screen.x * x_scale - 1.0) * aspect, -(screen.y) * y_scale + 1.0, 0.0));
	(void)win;
	return (vec3(screen.x, screen.y, 0.0));
}

/*
* check_ray_collision_sphere
* ray가 object의 어디에서 부딪히는지 계산한 hit 구조체를 반환한다.
*/
static t_hit	check_ray_collision_sphere(t_ray ray, t_objs *sphere)
{
	t_hit	hit;
	double	b;
	double	c;
	double	det;

	hit.d = -1.0;// 광선의 시작점으로부터 충돌지점까지의 거리 (float)
	hit.point = vec3(0.0, 0.0, 0.0); // 광선과 구가 충돌한 지점의 위치 (vec3)
	hit.normal = vec3(0.0, 0.0, 0.0); // 충돌 지점에서 구의 단위 법선 벡터(unit normal vector)
	b = 2.0 * v_dot(ray.normal, v_minus(ray.orig, sphere->coor)); // 근의 공식을 위한 변수
	c = v_dot(v_minus(ray.orig, sphere->coor), \
		v_minus(ray.orig, sphere->coor)) - pow((sphere->diameter / 2.0), 2.0); // 근의 공식을 위한 변수
	// det = v_dot(ray.normal, v_minus(ray.orig, sphere->coor));
	det = (b * b) - (4.0 * c);
	if (det >= 0.0)
	{
		hit.d = min_double((-b - sqrt(det)) / 2.0, (-b + sqrt(det)) / 2.0);
		hit.point = v_sum(ray.orig, v_mul_double(ray.normal, hit.d));
		hit.normal = norm_3d_vec(v_minus(hit.point, sphere->coor));
	}
	return (hit);
}

/*
* trace_ray
* ray를 쏴서 hit된 부분을 찾고 hit의 유효성을 판단.
* hit.d < 0 : 광선이 물체에 부딪히지 않는다.
* hit.d = 0 : 광선이 물체에 한번 부딪힌다.
* hit.d > 0 : 광선이 물체에 두번 부딪힌다.
*/

static t_vec3	trace_ray(t_info *info, t_ray ray)
{
	t_objs	*sphere;
	t_hit	hit;

	sphere = (t_objs *)(info->t_objs->content);
	hit = check_ray_collision_sphere(ray, sphere);
	if (hit.d < 0.0)
	{
		return (vec3(0.0, 0.0, 0.0));
	}
	else
	{
		// return (sphere->colors);
		return (v_mul_double(sphere->colors, hit.d));
	}
}



/*
* calculate_pixel_color
* 모니터에 그려질 2차원 (x, y) 좌표를 3차원으로 표현하기 위해서 모니터 비율에 맞춰서 3차원 벡터로 만들어줌.
*/
int	calculate_pixel_color(t_info *info, int x, int y)
{
	t_vec3	pixel_pos_world;
	t_vec3	ray_norm;
	t_ray	pixel_ray;

	pixel_pos_world = transform_screen_to_world(&(info->win), vec2(x, y));
	ray_norm = vec3(0.0, 0.0, 1.0);
	pixel_ray.orig = pixel_pos_world;
	pixel_ray.normal = ray_norm;
	t_vec3 color = clamp_3d(trace_ray(info, pixel_ray), 0.0, 255.0);
	return (create_trgb_int(1.0f, color.x, color.y, color.z));
}


/*
		vec3 traceRay(Ray &ray)
		{
			const Hit hit = sphere->IntersectRayCollision(ray);

			if (hit.d < 0.0f)
			{
				return vec3(0.0f);
			}
			else
			{
				return sphere->color * hit.d; // 깊이를 곱해서 입체감 만들기
			}
		}
*/

/*
					// 광선의 방향 벡터
					// 스크린에 수직인 z방향, 절대값 1.0인 유닉 벡터
					// Orthographic projection (정투영) vs perspective projection (원근투영)
					const auto rayDir = vec3(0.0f, 0.0f, 1.0f);

					Ray pixelRay{pixelPosWorld, rayDir};

					// index에는 size_t형 사용 (index가 음수일 수는 없으니까)
					// traceRay()의 반환형은 vec3 (RGB), A는 불필요
					pixels[size_t(i + width * j)] = vec4(traceRay(pixelRay), 1.0f);
*/
