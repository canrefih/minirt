#include "minirt.h"

double	check_height(t_ray ray, t_cylinder *cy, double t)
{
	t_vec3	p;
	double	h;

	p = vec_add(ray.origin, vec_scale(ray.direction, t));
	h = vec_dot(vec_sub(p, cy->center), cy->axis);
	if (h >= 0 && h <= cy->height)
		return (t);
	return (-1.0);
}

t_q_params	get_cy_params(t_ray ray, t_cylinder *cy)
{
	t_vec3	o_t;
	t_vec3	v;
	t_vec3	u;

	o_t = vec_sub(ray.origin, cy->center);
	v = vec_sub(ray.direction, vec_scale(cy->axis,
				vec_dot(ray.direction, cy->axis)));
	u = vec_sub(o_t, vec_scale(cy->axis, vec_dot(o_t, cy->axis)));
	return ((t_q_params){vec_dot(v, v), 2.0 * vec_dot(u, v),
		vec_dot(u, u) - pow(cy->diameter / 2.0, 2)});
}
