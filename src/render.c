#include "minirt.h"

static t_vec3	get_normal(t_object *obj, t_vec3 hit, t_vec3 cam_pos)
{
	t_vec3		normal;
	t_cylinder	*cy;
	double		h;

	if (obj->type == SPHERE)
		normal = vec_normalize(vec_sub(hit, ((t_sphere *)obj->shape)->center));
	else if (obj->type == PLANE)
		normal = ((t_plane *)obj->shape)->normal;
	else
	{
		cy = (t_cylinder *)obj->shape;
		h = vec_dot(vec_sub(hit, cy->center), cy->axis);
		if (h < 0.001)
			normal = vec_scale(cy->axis, -1.0);
		else if (h > cy->height - 0.001)
			normal = cy->axis;
		else
			normal = vec_normalize(vec_sub(vec_sub(hit, cy->center),
						vec_scale(cy->axis, h)));
	}
	if (vec_dot(normal, vec_sub(cam_pos, hit)) < 0)
		return (vec_scale(normal, -1.0));
	return (normal);
}

static t_color	get_obj_color(t_object *obj)
{
	if (obj->type == SPHERE)
		return (((t_sphere *)obj->shape)->color);
	if (obj->type == PLANE)
		return (((t_plane *)obj->shape)->color);
	return (((t_cylinder *)obj->shape)->color);
}

static void	render_pixel(t_rt *rt, int i, int j, t_ray ray)
{
	t_object	*hit_obj;
	t_hit_data	data;
	int			shadow;
	t_color		final_col;

	hit_obj = NULL;
	data.t = hit_scene(&rt->scene, ray, &hit_obj);
	if (data.t > 0 && hit_obj)
	{
		data.point = vec_add(ray.origin, vec_scale(ray.direction, data.t));
		data.normal = get_normal(hit_obj, data.point,
				rt->scene.camera.pos);
		data.color = get_obj_color(hit_obj);
		shadow = is_in_shadow(&rt->scene, data.point, rt->scene.light.pos);
		final_col = get_shaded_color(rt, data, data.color, shadow);
		my_mlx_pixel_put(&rt->mlx.img, i, j, (final_col.r << 16)
			| (final_col.g << 8) | final_col.b);
	}
	else
		my_mlx_pixel_put(&rt->mlx.img, i, j, 0x000010);
}

void	render(t_rt *rt)
{
	t_render_ctx	ctx;
	double			px;
	double			py;
	t_vec3			dir;

	ctx.aspect = (double)WIDTH / (double)HEIGHT;
	ctx.scale = tan((rt->scene.camera.fov * M_PI / 180.0) / 2.0);
	ctx.j = -1;
	while (++ctx.j < HEIGHT)
	{
		ctx.i = -1;
		while (++ctx.i < WIDTH)
		{
			px = (2.0 * ((ctx.i + 0.5) / (double)WIDTH) - 1.0)
				* ctx.aspect * ctx.scale;
			py = (2.0 * ((ctx.j + 0.5) / (double)HEIGHT) - 1.0) * ctx.scale;
			dir = vec_normalize(vec_add(vec_add(
							vec_scale(rt->scene.camera.right, px),
							vec_scale(rt->scene.camera.up, py)),
						rt->scene.camera.forward));
			render_pixel(rt, ctx.i, ctx.j,
				ray_create(rt->scene.camera.pos, dir));
		}
	}
}
