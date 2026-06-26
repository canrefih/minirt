/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:49:41 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:49:42 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1)
	{
		while (s1[s1_len])
			s1_len++;
	}
	if (s2)
	{
		while (s2[s2_len])
			s2_len++;
	}
	res = malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	if (s1)
		ft_memcpy(res, s1, s1_len);
	if (s2)
		ft_memcpy(res + s1_len, s2, s2_len);
	res[s1_len + s2_len] = '\0';
	return (res);
}

/*int main(void)
{
    char *s1 = "Hello ";
    char *s2 = "World!";
    char *res = ft_strjoin(s1, s2);
    if (res)
    {
        printf("%s", res);
        free(res);
    }
    return (0);
    
eğer s1 ve s2 null gelirse if kontrollerine girmediği için uzunlukları 
0 olup null terminated bir malloc kullandık
daha önceden oluşturduğumuz ft_memcpy ile belleğe istediğimiz 
uzunlukta stringi yazabildik
}*/
