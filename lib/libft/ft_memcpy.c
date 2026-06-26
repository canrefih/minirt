/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:13:55 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:14:44 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	i = 0;
	dest_char = (unsigned char *)dest;
	src_char = (const unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
    char dest[] = "Hello World";
    char src[] = "Fuck ";
    ft_memcpy(dest, src, 5);
    printf("%s", dest);
    return (0);
    
    void *, the pointed data can be changed
const void *, the pointed data can't be changed, just readable
}*/
