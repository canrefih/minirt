/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:49:59 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:50:00 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;
	size_t	dst_length;

	i = 0;
	while (dst[i])
		i++;
	dst_length = i;
	i = 0;
	while (src[i])
		i++;
	src_length = i;
	i = 0;
	if (size <= dst_length)
		return (src_length + size);
	while (i < (size - dst_length - 1) && src[i])
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (src_length + dst_length);
}

/*int main(void)
{
    char dest[20] = "Hello ";
    char src[] = "World";
    size_t len = ft_strlcat(dest, src, 20);
    printf("dest = %s\n", dest);
    printf("src len = %zu\n", len);
    return (0);
}*/
