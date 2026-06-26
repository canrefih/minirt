/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_print_char_bonus.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/29 09:53:41 by recan          #+#    #+#                */
/*   Updated: 2026/01/29 09:54:16 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c, t_flag *f)
{
	int	count;
	int	padding;

	count = 0;
	padding = f->width - 1;
	if (padding < 0)
		padding = 0;
	if (!f->minus)
	{
		while (padding--)
			count += ft_putchar(' ');
	}
	count += ft_putchar(c);
	if (f->minus)
	{
		while (padding--)
			count += ft_putchar(' ');
	}
	return (count);
}
