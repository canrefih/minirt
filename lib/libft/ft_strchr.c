/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:49:12 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:49:12 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	char_c;

	i = 0;
	char_c = (unsigned char)c;
	while (1)
	{
		if (s[i] == char_c)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
}

/*int main(void)
{
    char s[] = "Hello World";
    ft_strchr(s, 'd');
    return (0);
}*/
