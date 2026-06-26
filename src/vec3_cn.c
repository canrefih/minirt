#include "minirt.h"

double	vec_len(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec3	vec_normalize(t_vec3 v)
{
	double	len;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (len == 0)
		return (v);
	return ((t_vec3){
		v.x / len,
		v.y / len,
		v.z / len
	});
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	r;

	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return (r);
}
