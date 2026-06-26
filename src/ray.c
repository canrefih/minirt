#include "minirt.h"

t_ray	ray_create(t_vec3 origin, t_vec3 direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = vec_normalize(direction);
	return (r);
}

t_vec3	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_scale(ray.direction, t)));
}
