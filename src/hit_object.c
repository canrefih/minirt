#include "minirt.h"

double	hit_object(t_ray ray, t_object *obj)
{
	if (obj->type == SPHERE)
		return (sphere_intersect(ray, *(t_sphere *)obj->shape));
	if (obj->type == PLANE)
		return (plane_intersect(ray, *(t_plane *)obj->shape));
	if (obj->type == CYLINDER)
		return (hit_cylinder(ray, (t_cylinder *)obj->shape));
	return (-1);
}
