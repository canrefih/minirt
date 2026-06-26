/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_print_hex_bonus.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:44:22 by recan          #+#    #+#                */
/*   Updated: 2026/01/26 09:44:23 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, int upper)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef0123456789ABCDEF";
	base = base + 16 * upper;
	if (n >= 16)
		count += ft_puthex(n / 16, upper);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_calc_hex_len(unsigned int n, t_flag *f)
{
	int	len;

	len = 0;
	if (!(f->dot && f->precision == 0 && n == 0))
		len = ft_hex_len(n);
	if (f->precision > len)
		len = f->precision;
	if (f->hash && n != 0)
		len += 2;
	return (len);
}

static int	ft_hex_print_prefix(unsigned int n, int upper, t_flag *f)
{
	int	count;

	count = 0;
	if (f->hash && n != 0)
	{
		count += ft_putchar('0');
		if (upper)
			count += ft_putchar('X');
		else
			count += ft_putchar('x');
	}
	return (count);
}

int	ft_print_hex(unsigned int n, int upper, t_flag *f)
{
	int	count;
	int	len;
	int	padding;

	count = 0;
	len = ft_calc_hex_len(n, f);
	padding = f->width - len;
	if (padding < 0)
		padding = 0;
	if (!f->minus)
	{
		if (f->zero && !f->dot)
			count += ft_print_padding(padding, '0');
		else
			count += ft_print_padding(padding, ' ');
	}
	count += ft_hex_print_prefix(n, upper, f);
	if (f->precision > ft_hex_len(n))
		count += ft_print_padding(f->precision - ft_hex_len(n),
				'0');
	if (!(f->dot && f->precision == 0 && n == 0))
		count += ft_puthex(n, upper);
	if (f->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
