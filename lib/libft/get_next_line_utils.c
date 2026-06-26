/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 09:51:45 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 09:51:46 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(const char *s1, int size)
{
	char	*str;
	int		i;

	if (!s1 || size < 0)
		return (NULL);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
