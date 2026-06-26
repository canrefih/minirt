#include "minirt.h"
#include <fcntl.h>
#include <unistd.h>

static void	route_identifier(t_rt *rt, char **s)
{
	if (!ft_strncmp(s[0], "sp", 2) && ft_strlen(s[0]) == 2)
		parse_sphere(rt, s);
	else if (!ft_strncmp(s[0], "C", 1) && ft_strlen(s[0]) == 1)
		parse_camera(rt, s);
	else if (!ft_strncmp(s[0], "L", 1) && ft_strlen(s[0]) == 1)
		parse_light(rt, s);
	else if (!ft_strncmp(s[0], "A", 1) && ft_strlen(s[0]) == 1)
		parse_ambient(rt, s);
	else if (!ft_strncmp(s[0], "pl", 2) && ft_strlen(s[0]) == 2)
		parse_plane(rt, s);
	else if (!ft_strncmp(s[0], "cy", 2) && ft_strlen(s[0]) == 2)
		parse_cylinder(rt, s);
	else
	{
		printf("Error: Unknown identifier: %s\n", s[0]);
		free_split(s);
		exit(1);
	}
}

static void	parse_line(t_rt *rt, char *line)
{
	char	**s;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	if (line[0] == '\0')
		return ;
	s = ft_split(line, ' ');
	if (!s || !s[0])
	{
		free_split(s);
		return ;
	}
	route_identifier(rt, s);
	free_split(s);
}

void	parse_scene(t_rt *rt, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open file\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		parse_line(rt, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
