#include "minirt.h"

void	init_mlx(t_rt *rt)
{
	rt->mlx.mlx = mlx_init();
	rt->mlx.win = mlx_new_window(rt->mlx.mlx, WIDTH, HEIGHT, "minirt");
	rt->mlx.img.img = mlx_new_image(rt->mlx.mlx, WIDTH, HEIGHT);
	rt->mlx.img.addr = mlx_get_data_addr(rt->mlx.img.img, &rt->mlx.img.bpp,
			&rt->mlx.img.line_len, &rt->mlx.img.endian);
}

void	init_default_camera(t_rt *rt)
{
	rt->scene.camera.pos = vec3(0, 0, 0);
	rt->scene.camera.forward = vec3(0, 0, 1);
	rt->scene.camera.right = vec3(1, 0, 0);
	rt->scene.camera.up = vec3(0, 1, 0);
	rt->scene.camera.fov = 90;
	rt->scene.objects = NULL;
}

void	free_objects(t_object *obj)
{
	t_object	*temp;

	while (obj)
	{
		temp = obj;
		obj = obj->next;
		free(temp->shape);
		free(temp);
	}
}

int	close_window(void *param)
{
	t_rt	*rt;

	rt = (t_rt *)param;
	if (rt)
	{
		free_objects(rt->scene.objects);
		mlx_destroy_image(rt->mlx.mlx, rt->mlx.img.img);
		mlx_destroy_window(rt->mlx.mlx, rt->mlx.win);
	}
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_rt *rt)
{
	if (keycode == 65307)
		close_window(rt);
	return (0);
}
