/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putnbr_bonus.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:44:53 by recan          #+#    #+#                */
/*   Updated: 2026/01/26 09:44:59 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_sign(long *nb, t_flag *f)
{
	int	count;

	count = 0;
	if (*nb < 0)
	{
		count += write(1, "-", 1);
		*nb = -*nb;
	}
	else
	{
		if (f->plus)
			count += write(1, "+", 1);
		else if (f->space)
			count += write(1, " ", 1);
	}
	return (count);
}

char	ft_get_pad_char(t_flag *f)
{
	if (f->zero && !f->minus && !f->dot)
		return ('0');
	return (' ');
}

int	ft_get_nbr_len(long nb, t_flag *f)
{
	int	len;

	len = 1;
	if (f->dot && f->precision == 0 && nb == 0)
		return (0);
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_get_sign_len(long nb, t_flag *f)
{
	if (nb < 0 || f->space)
		return (1);
	return (0);
}
