/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_print_str_bonus.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:44:36 by recan          #+#    #+#                */
/*   Updated: 2026/01/26 09:44:37 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_str_len(char *str, t_flag *f)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len] && (!f->dot || len < f->precision))
		len++;
	return (len);
}

int	ft_print_padding(int width, char pad)
{
	int	count;

	count = 0;
	while (width-- > 0)
		count += ft_putchar(pad);
	return (count);
}

int	ft_print_str(char *str, t_flag *f)
{
	int	count;
	int	len;
	int	padding;
	int	i;

	count = 0;
	i = 0;
	if (!str)
	{
		if (f->dot)
			return (0);
		str = "(null)";
	}
	len = ft_get_str_len(str, f);
	padding = f->width - len;
	if (padding < 0)
		padding = 0;
	if (!f->minus)
		count += ft_print_padding(padding, ' ');
	while (i < len)
		count += ft_putchar(str[i++]);
	if (f->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
