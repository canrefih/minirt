/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 10:21:20 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 10:21:21 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list arg, const char str)
{
	int		count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (str == 's')
		count += ft_print_str(va_arg(arg, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (str == 'x')
		count += ft_print_hex(va_arg(arg, unsigned int), 0);
	else if (str == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), 1);
	else if (str == 'u')
		count += ft_putunbr(va_arg(arg, unsigned int));
	else if (str == 'p')
		count += ft_putptr(va_arg(arg, unsigned long long));
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_print_format(arg, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
