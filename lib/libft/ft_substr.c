/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:29:31 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 11:29:33 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	s_len;

	i = 0;
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main(void)
{
    char *str = ft_substr("Ben annemi çok seviyorum.", 4, 30);
    printf("%s", str);
    free(str);
    return (0);
    
    eğer start stringin uzunluğundan büyükse direkt boş stringle bitir
eğer len, starttan stringin sonuna kadar uzaklıktan daha büyükse kırpma yaptık.
}*/
