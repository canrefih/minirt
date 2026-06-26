#include "minirt.h"

t_vec3	parse_vec3(char *str)
{
	char	**p;
	t_vec3	v;
	int		i;

	p = ft_split(str, ',');
	if (!p || !p[0] || !p[1] || !p[2] || p[3] != NULL)
	{
		free_split(p);
		printf("Error: Invalid vector format (needs X,Y,Z)\n");
		exit(1);
	}
	if (!is_valid_float(p[0]) || !is_valid_float(p[1]) || !is_valid_float(p[2]))
	{
		free_split(p);
		printf("Error: Invalid vector values (must be valid floats)\n");
		exit(1);
	}
	v.x = ft_atof(p[0]);
	v.y = ft_atof(p[1]);
	v.z = ft_atof(p[2]);
	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
	return (v);
}

void	free_split(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return ;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

t_color	parse_color(char *s)
{
	t_color	c;
	char	**p;

	p = ft_split(s, ',');
	if (!p || !p[0] || !p[1] || !p[2])
	{
		free_split(p);
		printf("Error: Invalid color format (needs R,G,B)\n");
		exit(1);
	}
	if (!is_valid_int(p[0]) || !is_valid_int(p[1]) || !is_valid_int(p[2]))
	{
		free_split(p);
		printf("Error: Invalid color values (must be valid integers)\n");
		exit(1);
	}
	c.r = ft_atoi(p[0]);
	c.g = ft_atoi(p[1]);
	c.b = ft_atoi(p[2]);
	free_split(p);
	return (c);
}

static t_color	calculate_light(t_rt *rt, t_vec3 normal, t_vec3 hit, int shadow)
{
	t_color	res;
	double	diff;

	res.r = rt->scene.ambient.ratio * rt->scene.ambient.color.r;
	res.g = rt->scene.ambient.ratio * rt->scene.ambient.color.g;
	res.b = rt->scene.ambient.ratio * rt->scene.ambient.color.b;
	if (!shadow)
	{
		diff = fmax(0.0, vec_dot(normal,
					vec_normalize(vec_sub(rt->scene.light.pos, hit))));
		diff *= rt->scene.light.intensity;
		res.r += diff * rt->scene.light.color.r;
		res.g += diff * rt->scene.light.color.g;
		res.b += diff * rt->scene.light.color.b;
	}
	return (res);
}

t_color	get_shaded_color(t_rt *rt, t_hit_data data, t_color base, int shadow)
{
	t_color	light;
	t_color	res;

	light = calculate_light(rt, data.normal, data.point, shadow);
	res.r = (int)fmin(255, (light.r * (base.r / 255.0)));
	res.g = (int)fmin(255, (light.g * (base.g / 255.0)));
	res.b = (int)fmin(255, (light.b * (base.b / 255.0)));
	return (res);
}
