/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putunbr_bonus.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:45:15 by recan          #+#    #+#                */
/*   Updated: 2026/01/26 09:45:16 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_unbr_len(unsigned int n, t_flag *f)
{
	int	len;

	len = 1;
	if (f->dot && f->precision == 0 && n == 0)
		return (0);
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_putunbr_recursive(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr_recursive(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

static int	ft_unbr_padding_before_and_zero(int content_len, int len, t_flag *f)
{
	int		count;
	int		padding;
	char	pad;

	count = 0;
	if (!f->minus)
	{
		padding = f->width - content_len;
		if (padding < 0)
			padding = 0;
		if (f->zero && !f->dot)
			pad = '0';
		else
			pad = ' ';
		while (padding-- > 0)
			count += ft_putchar(pad);
	}
	padding = f->precision - len;
	while (f->dot && padding-- > 0)
		count += ft_putchar('0');
	return (count);
}

static int	ft_unbr_padding_after(int content_len, t_flag *f)
{
	int	count;
	int	padding;

	count = 0;
	if (f->minus)
	{
		padding = f->width - content_len;
		if (padding < 0)
			padding = 0;
		while (padding-- > 0)
			count += ft_putchar(' ');
	}
	return (count);
}

int	ft_putunbr(unsigned int n, t_flag *f)
{
	int	count;
	int	len;
	int	content_len;

	count = 0;
	len = ft_get_unbr_len(n, f);
	if (f->precision > len)
		content_len = f->precision;
	else
		content_len = len;
	count += ft_unbr_padding_before_and_zero(content_len, len, f);
	if (!(f->dot && f->precision == 0 && n == 0))
		count += ft_putunbr_recursive(n);
	count += ft_unbr_padding_after(content_len, f);
	return (count);
}
