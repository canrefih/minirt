/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:50:18 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:50:19 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;
	char			c;

	i = 0;
	while (s[i])
		i++;
	arr = malloc(i + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c = f(i, s[i]);
		arr[i] = c;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

/*char f(unsigned int i, char c)
{
    if (i % 2 == 1)
        return ('*');
    return (c);
}

int main(void)
{
    char *res = ft_strmapi("Hello", f);
    if (res)
    {
        printf("%s", res);
        free(res);
    }
    return (0);
    
char (*f)(unsigned int, char) 
f fonksiyonu char ama strmapi bir pointer döndürüyor
char *(*f)(unsigned int, char) hem f hem de strmapi bir pointer döndürüyor
}*/
