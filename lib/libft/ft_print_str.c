/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_print_str.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 10:21:53 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 10:21:54 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
