/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 09:50:09 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 09:51:25 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_clean(char *line, int bytes)
{
	if (bytes < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*ft_read_from_file(int fd, char *line)
{
	char	*buff;
	char	*tmp;
	int		bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && ft_checkstr(line) < 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buff[bytes] = '\0';
		tmp = line;
		line = ft_strjoin(line, buff);
		if (tmp)
			free(tmp);
	}
	free(buff);
	return (ft_clean(line, bytes));
}

static char	*ft_extract_line(char **line)
{
	char	*tmp;
	char	*extract;
	int		i;
	int		len;

	if (!*line || !**line)
		return (NULL);
	i = ft_checkstr(*line);
	if (i >= 0)
	{
		extract = ft_strndup(*line, i + 1);
		len = ft_strlen(*line) - (i + 1);
		if (len > 0)
			tmp = ft_strndup(*line + i + 1, len);
		else
			tmp = NULL;
		free(*line);
		*line = tmp;
		return (extract);
	}
	extract = ft_strndup(*line, ft_strlen(*line));
	free(*line);
	*line = NULL;
	return (extract);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_from_file(fd, line);
	if (!line)
		return (NULL);
	return (ft_extract_line(&line));
}
