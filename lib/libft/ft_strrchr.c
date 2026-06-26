/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:50:39 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 14:25:46 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	char_c;
	char			*temp;

	i = 0;
	temp = NULL;
	char_c = (unsigned char)c;
	while (1)
	{
		if (s[i] == char_c)
			temp = (char *)&s[i];
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (temp);
}

/*int main(void)
{
    char s[] = "Hello World";
    ft_strrchr(s, 'o');
    return (0);
    
    char cast ederek const tan kurtulup return edebiliyor olduk
&s[i] bellek adresini tutuyor
}*/
