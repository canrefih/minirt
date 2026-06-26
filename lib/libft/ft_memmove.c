/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:15:05 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:15:55 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	dest_char = (unsigned char *)dest;
	src_char = (const unsigned char *)src;
	if ((!dest && !src) || src == dest || n == 0)
		return (dest);
	if (dest_char < src_char)
	{
		i = 0;
		while (i < n)
		{
			dest_char[i] = src_char[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			dest_char[i] = src_char[i];
	}
	return (dest);
}

/*int main(void)
{
    char dest[] = "Hello World";
    char src[] = "Fuck ";
    ft_memmove(dest, src, 5);
    return (0);
}*/
