/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:44:11 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:45:15 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int main(void)
{
    char str[] = "Hello";
    ft_memset(str, '*', 2);
    return (0);
    
    unsigned int, 0 4,294,967,295
signed int, -2,147,483,648 2,147,483,647
int, is also signed int
size_t, is also unsigned int but greater values for memory calculation preferred
char, no guarantee up to compiler
unsigned char, 0 255 for memory calculation preferred
signed char, -128 127
void, no return value
void *, returns the address of the pointer
void *s, unknown type of pointer
int cast,
char cast,
pointer cast, even if we cast
}*/
