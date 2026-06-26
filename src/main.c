#include "minirt.h"

static int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	return (len >= 3 && ft_strncmp(file + len - 3, ".rt", 3) == 0);
}

int	main(int argc, char **argv)
{
	t_rt	rt;

	ft_memset(&rt, 0, sizeof(t_rt));
	if (argc != 2 || !check_extension(argv[1]))
	{
		printf("Error\nUsage: ./minirt scene.rt\n");
		return (1);
	}
	init_mlx(&rt);
	init_default_camera(&rt);
	parse_scene(&rt, argv[1]);
	render(&rt);
	mlx_put_image_to_window(rt.mlx.mlx, rt.mlx.win, rt.mlx.img.img, 0, 0);
	mlx_hook(rt.mlx.win, 17, 0, close_window, &rt);
	mlx_hook(rt.mlx.win, 2, 1L << 0, key_hook, &rt);
	mlx_loop(rt.mlx.mlx);
	return (0);
}
