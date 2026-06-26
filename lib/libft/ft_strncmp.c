/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:50:27 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:50:28 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	i = 0;
	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && s1_uc[i] && s2_uc[i])
	{
		if ((s1_uc[i] != s2_uc[i]) || i == n - 1)
			return (s1_uc[i] - s2_uc[i]);
		i++;
	}
	return (s1_uc[i] - s2_uc[i]);
}

/*int main(void)
{
    ft_strncmp("Hello", "Hell0", 5);
    return (0);
}*/
