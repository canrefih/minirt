#include "minirt.h"

void	parse_cylinder(t_rt *rt, char **s)
{
	t_object	*obj;
	t_cylinder	*cy;

	if (arr_len(s) != 6)
	{
		printf("Error: Invalid Cylinder params\n");
		exit(1);
	}
	obj = malloc(sizeof(t_object));
	cy = malloc(sizeof(t_cylinder));
	cy->center = parse_vec3(s[1]);
	cy->axis = vec_normalize(parse_vec3(s[2]));
	cy->diameter = ft_atof(s[3]);
	cy->height = ft_atof(s[4]);
	cy->color = parse_color(s[5]);
	if (cy->diameter <= 0 || cy->height <= 0)
	{
		printf("Error: Invalid Cyl dimensions\n");
		exit(1);
	}
	obj->type = CYLINDER;
	obj->shape = cy;
	obj->next = rt->scene.objects;
	rt->scene.objects = obj;
}

double	hit_cylinder_body(t_ray ray, t_cylinder *cy)
{
	t_q_params	q;
	double		delta;
	double		t;

	q = get_cy_params(ray, cy);
	delta = q.b * q.b - 4.0 * q.a * q.c;
	if (delta < 0)
		return (-1.0);
	t = check_height(ray, cy, (-q.b - sqrt(delta)) / (2.0 * q.a));
	if (t > 0.001)
		return (t);
	t = check_height(ray, cy, (-q.b + sqrt(delta)) / (2.0 * q.a));
	if (t > 0.001)
		return (t);
	return (-1.0);
}

double	hit_disk(t_ray ray, t_vec3 center, t_vec3 normal, double radius)
{
	double	dot_dn;
	double	t;
	double	dist;
	t_vec3	p;

	dot_dn = vec_dot(ray.direction, normal);
	if (fabs(dot_dn) < 1e-6)
		return (-1.0);
	t = vec_dot(vec_sub(center, ray.origin), normal) / dot_dn;
	if (t < 0.001)
		return (-1.0);
	p = vec_add(ray.origin, vec_scale(ray.direction, t));
	dist = vec_len(vec_sub(p, center));
	if (dist <= radius)
		return (t);
	return (-1.0);
}

double	hit_cylinder_caps(t_ray ray, t_cylinder *cy)
{
	t_vec3	top_center;
	double	t_cap1;
	double	t_cap2;
	double	radius;

	radius = cy->diameter / 2.0;
	top_center = vec_add(cy->center, vec_scale(cy->axis, cy->height));
	t_cap1 = hit_disk(ray, cy->center, vec_scale(cy->axis, -1.0), radius);
	t_cap2 = hit_disk(ray, top_center, cy->axis, radius);
	if (t_cap1 > 0.001 && t_cap2 > 0.001)
	{
		if (t_cap1 < t_cap2)
			return (t_cap1);
		return (t_cap2);
	}
	if (t_cap1 > 0.001)
		return (t_cap1);
	if (t_cap2 > 0.001)
		return (t_cap2);
	return (-1.0);
}

double	hit_cylinder(t_ray ray, t_cylinder *cy)
{
	double	t_body;
	double	t_caps;

	t_body = hit_cylinder_body(ray, cy);
	t_caps = hit_cylinder_caps(ray, cy);
	if (t_body > 0.001 && t_caps > 0.001)
	{
		if (t_body < t_caps)
			return (t_body);
		return (t_caps);
	}
	if (t_body > 0.001)
		return (t_body);
	if (t_caps > 0.001)
		return (t_caps);
	return (-1.0);
}
