/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_parse_bonus.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:43:58 by recan          #+#    #+#                */
/*   Updated: 2026/01/26 11:17:29 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_flag(t_flag *f)
{
	f->minus = 0;
	f->zero = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
	f->spec = 0;
}

void	ft_parse_flags(const char *format, int *i, t_flag *f)
{
	while (format[*i] == '-' || format[*i] == '0'
		|| format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
	{
		if (format[*i] == '-')
			f->minus = 1;
		else if (format[*i] == '0')
			f->zero = 1;
		else if (format[*i] == '+')
			f->plus = 1;
		else if (format[*i] == ' ')
			f->space = 1;
		else if (format[*i] == '#')
			f->hash = 1;
		(*i)++;
	}
}

void	ft_parse_width(const char *format, int *i, t_flag *f)
{
	while (ft_isdigit(format[*i]))
	{
		f->width = f->width * 10 + (format[*i] - '0');
		(*i)++;
	}
}

void	ft_parse_precision(const char *format, int *i, t_flag *f)
{
	if (format[*i] == '.')
	{
		f->dot = 1;
		f->precision = 0;
		(*i)++;
		while (ft_isdigit(format[*i]))
		{
			f->precision = f->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
}
