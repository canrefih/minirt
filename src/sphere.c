#include "minirt.h"

static double	solve_quadratic(double a, double b, double c)
{
	double	discriminant;
	double	sqrt_d;
	double	t1;
	double	t2;

	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (-1.0);
	sqrt_d = sqrt(discriminant);
	t1 = (-b - sqrt_d) / (2.0 * a);
	t2 = (-b + sqrt_d) / (2.0 * a);
	if (t1 > 0.001)
		return (t1);
	if (t2 > 0.001)
		return (t2);
	return (-1.0);
}

void	parse_sphere(t_rt *rt, char **s)
{
	t_object	*obj;
	t_sphere	*sp;

	if (arr_len(s) != 4)
	{
		printf("Error: Invalid Sphere params\n");
		exit(1);
	}
	obj = malloc(sizeof(t_object));
	sp = malloc(sizeof(t_sphere));
	sp->center = parse_vec3(s[1]);
	sp->diameter = ft_atof(s[2]);
	sp->color = parse_color(s[3]);
	if (sp->diameter <= 0)
	{
		printf("Error: Invalid Sphere diameter\n");
		exit(1);
	}
	obj->shape = sp;
	obj->type = SPHERE;
	obj->next = rt->scene.objects;
	rt->scene.objects = obj;
}

double	sphere_intersect(t_ray ray, t_sphere sphere)
{
	t_vec3	oc;
	double	radius;
	double	a;
	double	b;
	double	c;

	oc = vec_sub(ray.origin, sphere.center);
	radius = sphere.diameter * 0.5;
	a = vec_dot(ray.direction, ray.direction);
	b = 2.0 * vec_dot(oc, ray.direction);
	c = vec_dot(oc, oc) - (radius * radius);
	return (solve_quadratic(a, b, c));
}
