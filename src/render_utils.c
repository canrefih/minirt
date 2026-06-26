#include "minirt.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_len
			+ x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_sphere_lighting(t_vec3 hit, t_sphere sp, t_vec3 light_pos)
{
	t_vec3	normal;
	t_vec3	light_dir;
	double	intensity;

	normal = vec_normalize(vec_sub(hit, sp.center));
	light_dir = vec_normalize(vec_sub(light_pos, hit));
	intensity = vec_dot(normal, light_dir);
	if (intensity < 0)
		intensity = 0;
	return ((int)(255 * intensity));
}

double	hit_scene(t_scene *scene, t_ray ray, t_object **hit_obj)
{
	t_object	*curr;
	double		closest_t;
	double		temp_t;
	int			hit;

	curr = scene->objects;
	closest_t = 1e30;
	hit = 0;
	*hit_obj = NULL;
	while (curr)
	{
		temp_t = hit_object(ray, curr);
		if (temp_t > 0.001 && temp_t < closest_t)
		{
			closest_t = temp_t;
			*hit_obj = curr;
			hit = 1;
		}
		curr = curr->next;
	}
	if (hit)
		return (closest_t);
	return (-1.0);
}

int	is_in_shadow(t_scene *scene, t_vec3 hit, t_vec3 light_pos)
{
	t_object	*tmp;
	t_ray		shadow_ray;
	t_vec3		dir;
	double		t;
	double		light_dist;

	dir = vec_sub(light_pos, hit);
	light_dist = vec_len(dir);
	dir = vec_normalize(dir);
	shadow_ray = ray_create(vec_add(hit, vec_scale(dir, 0.0001)), dir);
	tmp = scene->objects;
	while (tmp)
	{
		t = hit_object(shadow_ray, tmp);
		if (t > 0.001 && t < light_dist)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
