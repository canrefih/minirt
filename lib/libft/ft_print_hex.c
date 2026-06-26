/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_print_hex.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 10:21:35 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 10:21:37 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, int upper)
{
	int	count;
	char	
		*base;

	count = 0;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_print_hex(n / 16, upper);
	count += ft_putchar(base[n % 16]);
	return (count);
}
