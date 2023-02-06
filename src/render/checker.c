#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"
#include "window.h"

#define BLACK 0
#define WHITE 1

t_vec3	uv_pattern_at(t_vec4 checkers, double u, double v)
{
	const double	u2 = floor(u * checkers.x1);
	const double	v2 = floor(v * checkers.x1);
	const int		i = u2 + v2;

	if (i % 2 == 0)
		return (vec3(0, 0, 0));
	else
		return (vec3(255, 255, 255));
}

double	spherical_map_u(t_hit hit)
{
	const double	theta = atan2(hit.normal.x, hit.normal.z);
	const double	raw_u = theta / (2 * PI);

	return (1 - (raw_u + 0.5));
}

double	spherical_map_v(t_hit hit)
{
	const t_vec3	vec = v_change_minus(hit.normal);
	const double	radius = v_len(vec);

	return (1 - (acos(hit.normal.y / radius) / PI));
}

void	checker(t_obj *sphere, t_hit hit)
{
	const t_vec4	checkers = vec4(8, 2, BLACK, WHITE);
	const t_vec3	d = v_change_minus(hit.normal);
	const t_vec3	color = uv_pattern_at(checkers, \
		spherical_map_u(hit), spherical_map_v(hit));

	sphere->colors = color;
}

/// @brief object의 color를 texture color로 바꿀 수 있다..
/// @param obj 바꾸고 싶은 object
/// @param hit obj에 부딪힌 hit
/// @return
void	get_texture_color(t_obj *obj, t_ray ray, t_hit *hit)
{
	const t_vec3	d = v_change_minus(hit->normal);
	const double	u = spherical_map_u(*hit);
	const double	v = spherical_map_v(*hit);

	obj->colors = get_texture_image_color(&obj->texture, vec2(u, v));
	if (obj->texture_normal.type == NORMAL)
		copy_vector_value(&hit->normal, sample_normal_map(&obj->texture_normal, \
			vec2(u, v), hit, v_cross(ray.normal, hit->normal)));
}
