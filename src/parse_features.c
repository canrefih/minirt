#include "minirt.h"

void	parse_camera(t_rt *rt, char **s)
{
	t_vec3	world_up;

	if (arr_len(s) != 4)
	{
		printf("Error: Invalid Camera params\n");
		exit(1);
	}
	rt->scene.camera.pos = parse_vec3(s[1]);
	rt->scene.camera.forward = vec_normalize(parse_vec3(s[2]));
	rt->scene.camera.fov = ft_atof(s[3]);
	world_up = vec3(0, 1, 0);
	if (fabs(rt->scene.camera.forward.x) < 1e-6
		&& fabs(rt->scene.camera.forward.z) < 1e-6)
	{
		if (rt->scene.camera.forward.y > 0)
			world_up = vec3(0, 0, -1);
		else
			world_up = vec3(0, 0, 1);
	}
	rt->scene.camera.right = vec_normalize(vec_cross(world_up,
				rt->scene.camera.forward));
	rt->scene.camera.up = vec_cross(rt->scene.camera.right,
			rt->scene.camera.forward);
}

void	parse_light(t_rt *rt, char **s)
{
	if (arr_len(s) != 4)
	{
		printf("Error: Invalid Light params\n");
		exit(1);
	}
	rt->scene.light.pos = parse_vec3(s[1]);
	rt->scene.light.intensity = ft_atof(s[2]);
	rt->scene.light.color = parse_color(s[3]);
	if (rt->scene.light.intensity < 0.0 || rt->scene.light.intensity > 1.0)
	{
		printf("Error: Light intensity must be between 0.0 and 1.0\n");
		exit(1);
	}
}

void	parse_ambient(t_rt *rt, char **s)
{
	if (arr_len(s) != 3)
	{
		printf("Error: Invalid Ambient params\n");
		exit(1);
	}
	rt->scene.ambient.ratio = ft_atof(s[1]);
	rt->scene.ambient.color = parse_color(s[2]);
	if (rt->scene.ambient.ratio < 0.0 || rt->scene.ambient.ratio > 1.0)
	{
		printf("Error: Ambient ratio must be between 0.0 and 1.0\n");
		exit(1);
	}
}
