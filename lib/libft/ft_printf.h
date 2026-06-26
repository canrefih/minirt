/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 10:21:28 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 10:21:30 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_print_str(char *str);
int	ft_putnbr(long n);
int	ft_putunbr(unsigned int n);
int	ft_print_hex(unsigned long long n, int upper);
int	ft_putptr(unsigned long long ptr);

#endif
