/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:46:52 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 13:46:56 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	if (n < -2147483647)
	{
		num = n;
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num = -num;
		}
		if (num > 9)
			ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}
