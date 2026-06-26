/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:31:20 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 11:31:21 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_check(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	sublen;
	char	*trim;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_check(s1[i], set))
		i++;
	j = len - 1;
	while (j > i && ft_check(s1[j], set))
		j--;
	sublen = j - i;
	trim = (char *)malloc(sizeof(char) * (sublen + 2));
	if (!trim)
		return (NULL);
	ft_memcpy(trim, s1 + i, sublen + 1);
	trim[sublen + 1] = '\0';
	return (trim);
}

/*int main(void)
{
    char *s1 = "-------Senicokseciyorum--------";
    char *set = "-";
    char *res = ft_strtrim(s1, set);
    if (res)
    {
        printf("%s", res);
        free(res);
    }
    return (0);
    eğer s1 ve s2 null gelirse if kontrollerine girmediği için 
    uzunlukları 0 olup null terminated bir malloc oluşturuyoruz
daha önceden oluşturduğumuz ft_memcpy ile belleğe istediğimiz 
uzunlukta stringi yazabildik
}*/
