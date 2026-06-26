#include "minirt.h"

double	plane_intersect(t_ray ray, t_plane pl)
{
	double	denom;
	double	t;
	t_vec3	p0l0;

	denom = vec_dot(pl.normal, ray.direction);
	if (fabs(denom) < 1e-6)
		return (-1.0);
	p0l0 = vec_sub(pl.point, ray.origin);
	t = vec_dot(p0l0, pl.normal) / denom;
	if (t > 0.001)
		return (t);
	return (-1.0);
}

void	parse_plane(t_rt *rt, char **s)
{
	t_object	*obj;
	t_plane		*pl;

	if (arr_len(s) != 4)
	{
		printf("Error: Invalid Plane params\n");
		exit(1);
	}
	obj = malloc(sizeof(t_object));
	pl = malloc(sizeof(t_plane));
	pl->point = parse_vec3(s[1]);
	pl->normal = vec_normalize(parse_vec3(s[2]));
	pl->color = parse_color(s[3]);
	obj->shape = pl;
	obj->type = PLANE;
	obj->next = rt->scene.objects;
	rt->scene.objects = obj;
}
