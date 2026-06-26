/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putunbr.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 10:22:22 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 10:22:23 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
