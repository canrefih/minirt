/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:50:33 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:50:33 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] != '\0'
			&& big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			++j;
		}
		++i;
	}
	return (NULL);
}

/*int main(void)
{
    ft_strnstr("rerieeffirefikrefiirefirefikeiri", "refik", 20);
    return (0);
    
    haystack bir dizi, char * cast edilebilir
haystack[i] bir char, char * cast edilemez 
çünkü tek bir karakterden dizi oluşturamayız
&haystack[i] de karakterin bellek adresi, char * cast edilebilir, 
o bellek adresinden sonraki değerleri getirir
return ederken char * a cast ediyoruz 
çünkü kaynak string pointerı değiştirmemeyi amaçlıyoruz.
}*/
