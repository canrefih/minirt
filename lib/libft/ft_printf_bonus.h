/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf_bonus.h                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/26 09:44:14 by recan          #+#    #+#                */
/*   Updated: 2026/01/27 11:24:52 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		dot;
	int		precision;
	char	spec;
}	t_flag;

int		ft_putchar(int c);

int		ft_print_char(char c, t_flag *f);

int		ft_printf(const char *format, ...);
int		ft_print_format(va_list arg, t_flag *f);
int		ft_parse_all(va_list arg, const char *format, t_flag *f, int *i);
void	ft_init_flag(t_flag *f);
void	ft_parse_flags(const char *format, int *i, t_flag *f);
void	ft_parse_width(const char *format, int *i, t_flag *f);
void	ft_parse_precision(const char *format, int *i, t_flag *f);
int		ft_print_str(char *str, t_flag *f);
int		ft_putnbr(int n, t_flag *f);
int		ft_print_sign(long *nb, t_flag *f);
char	ft_get_pad_char(t_flag *f);
int		ft_get_nbr_len(long nb, t_flag *f);
int		ft_get_sign_len(long nb, t_flag *f);
int		ft_print_padding(int len, char c);
int		ft_putunbr(unsigned int n, t_flag *f);

int		ft_putptr(unsigned long ptr, t_flag *f);

int		ft_print_hex(unsigned int n, int upper, t_flag *f);
int		ft_hex_len(unsigned int n);
int		ft_puthex(unsigned int n, int upper);
int		ft_calc_hex_len(unsigned int n, t_flag *f);
int		ft_print_hex_padding(unsigned int n, t_flag *f, int *len);

#endif
