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

int	ft_putnbr_rec(long nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_rec(nb / 10);
	c = (nb % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

static int	ft_get_content_len(int nbr_len, int sign_len, t_flag *f)
{
	int	content_len;

	content_len = nbr_len;
	if (f->dot && f->precision > nbr_len)
		content_len = f->precision;
	content_len += sign_len;
	return (content_len);
}

int	ft_handle_padding_before(t_flag *f, int nbr_len, int sign_len)
{
	int		count;
	int		content_len;
	char	pad;

	count = 0;
	content_len = ft_get_content_len(nbr_len, sign_len, f);
	pad = ft_get_pad_char(f);
	if (!f->minus && f->width > content_len)
		count += ft_print_padding(f->width - content_len, pad);
	return (count);
}

static int	ft_handle_padding_after(int content_len, t_flag *f)
{
	int	count;

	count = 0;
	if (f->minus && f->width > content_len)
		count += ft_print_padding(f->width - content_len, ' ');
	return (count);
}

int	ft_putnbr(int n, t_flag *f)
{
	long	nb;
	int		count;
	int		sign_len;
	int		nbr_len;
	int		content_len;

	nb = n;
	count = 0;
	sign_len = ft_get_sign_len(nb, f);
	nbr_len = ft_get_nbr_len(nb, f);
	content_len = ft_get_content_len(nbr_len, sign_len, f);
	count += ft_handle_padding_before(f, nbr_len, sign_len);
	count += ft_print_sign(&nb, f);
	if (f->dot && f->precision > nbr_len)
		count += ft_print_padding(f->precision - nbr_len, '0');
	if (!(f->dot && f->precision == 0 && n == 0))
		count += ft_putnbr_rec(nb);
	count += ft_handle_padding_after(content_len, f);
	return (count);
}
