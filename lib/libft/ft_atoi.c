/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:52:34 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 08:53:20 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*int main(void)
{
    ft_atoi("     -123456");
    return (0);
    
    int'ten char'a, char'dan int'e tip dönüşümüyle cast işlemlerini karıştırma!! 
- '0' inte, + '0' char'a çevirir. 
ama cast etmek değişkenin dönüşüm sonrası değerini bulur.
örneği '5' i int'e kast etmeye kalktığımızda ascii değerini buluruz. 
çünkü değişkenin tipi char.
}*/
