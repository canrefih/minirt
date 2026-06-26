/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putptr_bonus.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:45:06 by recan          #+#    #+#                */
/*   Updated: 2026/01/26 09:45:07 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(unsigned long num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr_hex(unsigned long n)
{
	if (n >= 16)
		ft_putptr_hex(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
}

static int	ft_calc_ptr_padding(unsigned long ptr, t_flag *f, int *len)
{
	int	num_len;
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += ft_putchar('(');
		count += ft_putchar('n');
		count += ft_putchar('i');
		count += ft_putchar('l');
		count += ft_putchar(')');
		return (count);
	}
	num_len = ft_ptr_len(ptr);
	if (f->dot && f->precision == 0 && ptr == 0)
		num_len = 0;
	*len = num_len + 2;
	if (f->precision > num_len)
		*len += f->precision - num_len;
	return (count);
}

static int	ft_print_width(t_flag *f, char c, int len)
{
	int	count;
	int	padding;

	count = 0;
	padding = f->width - len;
	if (padding < 0)
		padding = 0;
	while (padding-- > 0)
		count += ft_putchar(c);
	return (count);
}

int	ft_putptr(unsigned long ptr, t_flag *f)
{
	int	count;
	int	len;
	int	zero_pad;

	count = 0;
	count = ft_calc_ptr_padding(ptr, f, &len);
	if (ptr == 0)
		return (count);
	if (!f->minus)
		count += ft_print_width(f, ' ', len);
	count += ft_putchar('0');
	count += ft_putchar('x');
	zero_pad = f->precision - ft_ptr_len(ptr);
	if (zero_pad < 0)
		zero_pad = 0;
	while (f->dot && zero_pad-- > 0)
		count += ft_putchar('0');
	if (!(f->dot && f->precision == 0 && ptr == 0))
	{
		ft_putptr_hex(ptr);
		count += ft_ptr_len(ptr);
	}
	if (f->minus)
		count += ft_print_width(f, ' ', len);
	return (count);
}
