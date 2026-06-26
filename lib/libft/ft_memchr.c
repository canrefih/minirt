/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:10:42 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:12:14 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_char;
	unsigned char	c_char;

	i = 0;
	s_char = (unsigned char *)s;
	c_char = (unsigned char)c;
	while (i < n)
	{
		if (s_char[i] == c_char)
			return ((void *)&s_char[i]);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
    char s[] = "Hello";
    ft_memchr(s, 'o', 5);
    return (0);
    
    memory'ler raw memory üzerinde çalıştığı için \0 kontrolü yapılamaz. 
    eğer aranan kararkter buysa kod çalışmaz.
return tipi fonksiyonla aynı tipte olması lazım.
}*/
