/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:04:37 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 09:06:45 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}

/*int main(void)
{
    void *arr = ft_calloc(5, 4);
    if (arr)
    {
        free(arr);
    }
    return (0);
    
dönen değer her zaman fonksiyon tipinde olmalı
void pointer doğrudan kullanılamaz ptr[i] gibi, 
önce uygun tipe cast edilmeli.
belleği byte byte işlemek istediğimiz için de 
unsigned char seçtik 1 byte uzunluğu olan
}*/
