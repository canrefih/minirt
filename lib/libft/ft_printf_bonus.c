/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf_bonus.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:44:07 by recan          #+#    #+#                */
/*   Updated: 2026/01/26 09:44:08 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(va_list arg, t_flag *f)
{
	int	count;

	count = 0;
	if (f->spec == 'c')
		count += ft_print_char(va_arg(arg, int), f);
	else if (f->spec == 's')
		count += ft_print_str(va_arg(arg, char *), f);
	else if (f->spec == 'd' || f->spec == 'i')
		count += ft_putnbr(va_arg(arg, int), f);
	else if (f->spec == 'u')
		count += ft_putunbr(va_arg(arg, unsigned int), f);
	else if (f->spec == 'x')
		count += ft_print_hex(va_arg(arg, unsigned int), 0, f);
	else if (f->spec == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), 1, f);
	else if (f->spec == 'p')
		count += ft_putptr(va_arg(arg, unsigned long), f);
	else if (f->spec == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_parse_all(va_list arg, const char *format, t_flag *f, int *i)
{
	int	count;

	count = 0;
	ft_parse_flags(format, i, f);
	ft_parse_width(format, i, f);
	ft_parse_precision(format, i, f);
	f->spec = format[*i];
	count += ft_print_format(arg, f);
	(*i)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;
	t_flag	f;

	i = 0;
	va_start(arg, format);
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_init_flag(&f);
			count += ft_parse_all(arg, format, &f, &i);
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
