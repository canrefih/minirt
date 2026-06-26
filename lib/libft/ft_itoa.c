/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:01:37 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 12:06:17 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	num;

	len = ft_length(n);
	res = malloc(len + 1);
	num = n;
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = '0';
	while (num > 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

/*int main(void)
{
    int n = -2147483648;
    char *res = ft_itoa(n);
    printf("%s", res);
    return (0);
    
    eğer küçükse 1, değilse 0 yapan ternary operator, üçlü koşul
}*/
