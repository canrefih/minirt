/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:50:04 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:50:04 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	while (src[i])
		i++;
	src_length = i;
	i = 0;
	if (size == 0)
		return (src_length);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_length);
}

/*int main(void)
{
    char dest[4];
    char src[] = "Hello";
    size_t len = ft_strlcpy(dest, src, 4);
    printf("dest = %s\n", dest);
    printf("src len = %zu\n", len);
    return (0);
}*/
