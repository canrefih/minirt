/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:49:34 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:49:35 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void f(unsigned int i, char *c)
{
    if (i % 2 == 1)
         *c = '*';
}

int main(void)
{
    char s[] = "Hello";
    ft_striteri(s, f);
    return (0);
    
    *c = value
c = address
direkt string verdiğimizde fonksiyon içerisinde read-only, 
ft_striteri("Hello", f)
değişken şeklinde tanımlayıp verdiğimizde değiştirilebilir oluyor. 
ft_striteri(s, f)
}*/
